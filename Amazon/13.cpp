class Solution {
public:
    
    void rott(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&time,int t,
             vector<vector<int>>&visited){
        // cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1 
           || visited[i][j]==1 || time[i][j]<t)
            return;
        time[i][j]=min(time[i][j],t);
        // visited[i][j]=1;
        t++;
        rott(i-1,j,grid,time,t,visited);
        rott(i+1,j,grid,time,t,visited);
        rott(i,j-1,grid,time,t,visited);
        rott(i,j+1,grid,time,t,visited);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>time(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    time[i][j]=INT_MAX;
            }
        }
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            vector<vector<int>>visited(n,vector<int>(m,0));
            rott(i-1,j,grid,time,1,visited);
            rott(i+1,j,grid,time,1,visited);
            rott(i,j-1,grid,time,1,visited);
            rott(i,j+1,grid,time,1,visited);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<time[i][j]<<endl;
                if(time[i][j]==INT_MAX)
                    return -1;
                ans=max(ans,time[i][j]);
            }
        }
        return ans;
    }
};
