class Solution {
public:
    
    bool dfs(vector<vector<int>>&v,vector<int>&visited,vector<int>&temp,int sv,stack<int>&st){
        visited[sv]=1;
        temp[sv]++;
        for(int i=0;i<v[sv].size();i++){
            if(!visited[v[sv][i]] && !dfs(v,visited,temp,v[sv][i],st))
                return false;
            if(visited[v[sv][i]])
                return false;
        }
        visited[sv]=0;
        if(temp[sv]==1)
            st.push(sv);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        vector<int>visited(numCourses,0),temp(numCourses,0),ans;
        stack<int>st;
        for(int i=0;i<prerequisites.size();i++){
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!temp[i] && !dfs(v,visited,temp,i,st))
               return ans;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
