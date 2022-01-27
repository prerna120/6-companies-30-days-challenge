//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    
    int ways(int i,int j,int x,int y,vector<vector<int>>&dp){
        if(i>x || j>y)
            return 0;
        if(i==x && j==y)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=ways(i+1,j,x,y,dp)+ways(i,j+1,x,y,dp);
    }
    
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return ways(0,0,a-1,b-1,dp);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends
