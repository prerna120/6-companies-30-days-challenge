#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    int mn=INT_MAX;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	   vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,-1));
	   for(int i=1;i<=sum/2;i++){
	       dp[0][i]=0;
	   }
	   for(int i=0;i<=n;i++){
	       dp[i][0]=1;
	   }
	   
	   for(int i=1;i<=n;i++){
	       for(int j=0;j<=sum/2;j++){
	           if(arr[i-1]<=j)
	            dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
	           else
	            dp[i][j]=dp[i-1][j];
	           if(i==n && dp[i][j]==true){
	            mn=min(mn,sum-2*j);
	           }
	       }
	   }
	   return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
