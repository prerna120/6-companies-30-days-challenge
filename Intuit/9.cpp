class Solution {
public:
    
    bool check(int i,int j,int n,int m,vector<vector<int>>& height,
                                                vector<vector<int>>&visited,int x,int y){
        return i>=0 && j>=0 && i<n && j<m && !visited[i][j] && height[i][j]>=height[x][y];
    }
    
    void bfs(int i,int j,vector<vector<int>>&v,vector<vector<int>>& heights,
                                                    vector<vector<int>>&visited){
        if(v[i][j]!=0)
            return;
        int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
        v[i][j]=1;
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k],ny=j+dy[k];
            if(check(nx,ny,v.size(),v[0].size(),heights,visited,i,j))
                bfs(nx,ny,v,heights,visited);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>ans,pacific(n,vector<int>(m,0)),atlantic=pacific;
        vector<vector<int>>visited(n,vector<int>(m,0)),t=visited;
        for(int i=0;i<n;i++){
            visited=t;
            bfs(i,0,pacific,heights,visited);
            visited=t;
            bfs(i,m-1,atlantic,heights,visited);
        }
        for(int j=0;j<m;j++){
            visited=t;
            bfs(0,j,pacific,heights,visited);
            visited=t;
            bfs(n-1,j,atlantic,heights,visited);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
