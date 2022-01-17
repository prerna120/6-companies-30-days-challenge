//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    long long int mod=1000000007;
  
    int kvowelwords(int N, int K) {
        // Write Your Code here
        vector<vector<long long int>>dp(N+1,vector<long long int>(K+1,1));
        for(int i=1;i<=N;i++){
            for(int j=0;j<=K;j++){
                dp[i][j]=(dp[i-1][K]*21)%mod;
                if(j>0)
                    dp[i][j]=(dp[i][j]+(dp[i-1][j-1]*5)%mod)%mod;
            }
        }
        return dp[N][K];
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
