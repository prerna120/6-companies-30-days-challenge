//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        vector<unordered_map<int,int>>dp(n);
        int ans=1;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                int diff=A[j]-A[i];
                if(dp[i].find(diff)!=dp[i].end())
                    dp[j][diff]=dp[i][diff]+1;
                else
                    dp[j][diff]=2;
                ans=max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
