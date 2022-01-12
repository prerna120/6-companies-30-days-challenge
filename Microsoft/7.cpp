#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    int bfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]==0)
            return 0;
        int dx[]={0,0,1,1,-1,-1,1,-1},dy[]={1,-1,1,-1,1,-1,0,0};
        visited[i][j]=1;
        int ones=1;
        for(int k=0;k<8;k++){
            ones+=bfs(i+dx[k],j+dy[k],visited,grid);
        }
        return ones;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),mx=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)
                    mx=max(mx,bfs(i,j,visited,grid));
            }
        }
        return mx;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
