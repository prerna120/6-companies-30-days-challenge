#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    
    long long int ways(int m,unordered_map<int,long long int>&dp){
        if(m<=0)
            return 0;
        if(m==1)
            return 1;
        if(dp.find(m)!=dp.end())
            return dp[m];
        if(m%2!=0)
            return dp[m]=ways(m-1,dp);
        return dp[m]=ways(m-1,dp)+1;
    }
    
    long long countWays(int m)
    {
        // your code here
        unordered_map<int,long long int>dp;
        return ways(m,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends
