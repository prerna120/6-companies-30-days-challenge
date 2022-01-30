class Solution {
public:
    
    int stones(int i,int j,vector<int>&piles,vector<vector<int>>&dp){
        if(i==j)
            return piles[i];
        if(i+1==j)
            return max(piles[i],piles[j]);
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(piles[i]+min(stones(i+2,j,piles,dp),stones(i+1,j-1,piles,dp)),
                   piles[j]+min(stones(i+1,j-1,piles,dp),stones(i,j-2,piles,dp)));
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum=0,alice=stones(0,n-1,piles,dp);
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }
        return sum-alice<alice;
    }
};
