#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int LCS(vector<int>v){
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            auto it=lower_bound(ans.begin(),ans.end(),v[i]);
            if(it!=ans.end())
                *it=v[i];
            else
                ans.push_back(v[i]);
        }
        return ans.size();
    }
  
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_map<int,int>um;
        for(int i=0;i<M;i++){
            um[B[i]]++;
        }
        vector<int>v;
        for(int i=0;i<N;i++){
            if(um.find(A[i])!=um.end())
                v.push_back(A[i]);
        }
        return N+M-(2*LCS(v));
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
