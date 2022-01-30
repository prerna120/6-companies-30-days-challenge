class Solution {
public:
    
    int bs(int l,int h,vector<vector<int>>&dp){
        if(l>h)
            return INT_MIN;
        if(l==h)
            return 0;
        if(dp[l][h]!=-1)
            return dp[l][h];
        int ans=INT_MAX;
        for(int i=l;i<=h;i++){
            ans=min(i+max(bs(i+1,h,dp),bs(l,i-1,dp)),ans);
            // cout<<i+max(bs(i+1,h,dp),bs(l,i-1,dp))<<endl;
        }
        return dp[l][h]=ans;
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return bs(1,n,dp);
    }
};
