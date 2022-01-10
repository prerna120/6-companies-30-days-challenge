// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // unordered_map<int,unordered_map<int,int>>dp;
  
    // int profit(int i,int A[],int N,int K,int bought){
    //     if(K==0 || i==N)
    //         return 0;
    //     if(dp.find(i)!=dp.end() && dp[i].find(K)!=dp[i].end())
    //         return dp[i][K];
    //     int ans=0;
    //     if(bought!=INT_MAX)
    //         ans=max(ans,A[i]-A[bought]+profit(i+1,A,N,K-1,INT_MAX));
    //     bought=min(bought,A[i]);
    //     ans=max(ans,profit(i+1,A,N,K,bought));
    //     return dp[i][K]=ans;
    // }
  
    int maxProfit(int K, int N, int A[]) {
        // code here
        // return profit(0,A,N,K,INT_MAX);
        vector<vector<int>>dp(K+1,vector<int>(N,0));
        for(int i=1;i<=K;i++){
            int mx=INT_MIN;
            for(int j=1;j<N;j++){
                mx=max(mx,dp[i-1][j-1]-A[j-1]);
                dp[i][j]=max(dp[i][j-1],mx+A[j]);
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
