
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void bfs(unordered_map<char,vector<char>>&v,unordered_map<char,int>&visited,char sv,stack<char>&st){
        visited[sv]=1;
        for(int i=0;i<v[sv].size();i++){
            if(!visited[v[sv][i]])
                bfs(v,visited,v[sv][i],st);
        }
        st.push(sv);
    }
    
    string findOrder(string dict[], int N, int K) {
        unordered_map<char,vector<char>>v;
        unordered_map<char,int>visited;
        string ans="";
        for(int i=1;i<N;i++){
            int j=0,size=min(dict[i-1].size(),dict[i].size());
            while(dict[i-1][j]==dict[i][j] && j<size){
                j++;
            }
            if(j!=size){
                if(v.count(dict[i-1][j])==0)
                    v[dict[i-1][j]]={};
                visited[dict[i-1][j]]=0;
                visited[dict[i][j]]=0;
                v[dict[i-1][j]].push_back(dict[i][j]);
            }
        }
        stack<char>st;
        for(auto i:visited){
            if(!i.second)
               bfs(v,visited,i.first,st); 
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
