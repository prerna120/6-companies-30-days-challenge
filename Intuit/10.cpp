class Solution {
public:
    
    void bfs(int n,vector<vector<int>>&adj,vector<int>&visited){
        queue<int>q;
        q.push(n);
        while(q.size()){
            int node=q.front();
            q.pop();
            visited[node]++;
            for(int i=0;i<visited.size();i++){
                if(adj[node][i]==1 && visited[i]==0)
                    q.push(i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,isConnected,visited);
                ans++;
            }
        }
        return ans;
    }
};
