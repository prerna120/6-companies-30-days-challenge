class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,unordered_map<int,double>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=succProb[i];
            adj[edges[i][1]][edges[i][0]]=succProb[i];
        }
        priority_queue<pair<double,int>>q;
        q.push({1,start});
        unordered_map<int,int>visited;
        while(!q.empty()){
            double prob=q.top().first;
            int node=q.top().second;
            q.pop();
            // cout<<node<<endl;
            if(node==end)
                return prob;
            if(visited.find(node)!=visited.end())
                continue;
            visited[node]=1;
            for(auto it:adj[node]){
                q.push({prob*it.second,it.first});
            }
        }
        return 0;
    }
};
