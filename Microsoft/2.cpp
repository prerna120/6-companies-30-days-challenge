#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&t_visited){
        if(t_visited[node])
            return true;
        t_visited[node]=1;
        if(!visited[node]){
            visited[node]=1;
            for(int i=0;i<adj[node].size();i++){
                if(dfs(adj[node][i],adj,visited,t_visited))
                    return true;
            }
        }
        t_visited[node]=0;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(N);
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<int>visited(N,0),t_visited(N,0);
	    for(int i=0;i<N;i++){
	        if(dfs(i,adj,visited,t_visited))
	            return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
