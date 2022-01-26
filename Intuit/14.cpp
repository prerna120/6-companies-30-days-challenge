class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int ans=-1,n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e6));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    dp[i][j]=0;
                else{
                    if(i>0)
                        dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
                    if(j>0)
                        dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==0){
                    if(i<n-1)
                        dp[i][j]=min(dp[i][j],1+dp[i+1][j]);
                    if(j<m-1)
                        dp[i][j]=min(dp[i][j],1+dp[i][j+1]);
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        if(ans==1e6)
            return -1;
        return ans;
    }
};
