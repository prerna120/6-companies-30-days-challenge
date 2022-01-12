#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to calculate span
// price[]: price array in input
// n: size of array

class Solution{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>a;
       stack<pair<int,int>>s;
       for(int i=0;i<n;i++){
           if(s.empty()){
               a.push_back(-1);
           }
           else if(!s.empty() && s.top().first>price[i]){
               a.push_back(s.top().second);
           }
           else{
               while(!s.empty() && s.top().first<=price[i]){
                   s.pop();
               }
               if(s.empty()){
                   a.push_back(-1);
               }
               else{
                   a.push_back(s.top().second);
               }
           }
           s.push({price[i],i});
       }
       
       for(int i=0;i<n;i++){
           a[i]=i-a[i];
       }
       
      return a; 
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
