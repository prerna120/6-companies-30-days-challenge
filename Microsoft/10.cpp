#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution
{
    public:
    
    // int sum(int arr[],int n,bool t){
    //     if(n==0)
    //         return 0;
    //     if(t==true){
    //         return arr[n-1]+sum(arr,n-1,false);
    //     }
    //     return max(sum(arr,n-1,false),sum(arr,n-1,true));
    // }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // return sum(arr,n,false);
        int inc=0,exc=0;
        for(int i=0;i<n;i++){
            int in=inc,ex=exc;
            inc=arr[i]+ex;
            exc=max(in,ex);
        }
        return max(inc,exc);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
