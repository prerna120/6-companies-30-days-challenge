// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        // code here
        vector<long long>dp(n+1,0);
        dp[0]=dp[1]=1;
        int mx=pow(n,1.0/x),mod=1e9+7;
        for(int i=2;i<=mx;i++){
            long long p=pow(i,x);
            for(int j=n;j>=p;j--){
                dp[j]+=dp[j-p];
                dp[j]%=mod;
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
