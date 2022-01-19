#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    rangee = findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

// } Driver Code Ends


// you are required to complete this function 
// function should print the required range
#include<queue>
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      //code here
      
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    int mx=INT_MIN,ans,range=INT_MAX;
    for(int i=0;i<k;i++){
        mx=max(mx,arr[i][0]);
        q.push({arr[i][0],{i,0}});
    }
    ans=mx;
    while(1){
        int val=q.top().first;
        int i=q.top().second.first;
        int j=q.top().second.second;
        q.pop();
        if(range>mx-val){
            range=mx-val;
            ans=mx;
        }
        if(j==n-1)
            break;
        else{
            q.push({arr[i][j+1],{i,j+1}});
            mx=max(mx,arr[i][j+1]);
        }
    }
    return pair<int,int>{ans-range,ans};
}
