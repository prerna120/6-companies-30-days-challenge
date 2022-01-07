// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    struct Trie{
        Trie*child[26];
        bool isEnd;
        Trie(){
            isEnd=false;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    
    void insert(Trie*t,string s){
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(t->child[index]==NULL)
                t->child[index]=new Trie();
            t=t->child[index];
        }
        t->isEnd=true;
    }
    
    Trie* search(Trie*t,string s){
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(t->child[index]==NULL)
                return NULL;
            t=t->child[index];
        }
        return t;
    }
    
    void find(Trie*t,string st,vector<string>&v){
        if(t->isEnd==true)
            v.push_back(st);
        for(int i=0;i<26;i++){
            if(t->child[i]){
                char c=i+'a';
                find(t->child[i],st+c,v);
            }
        }
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans(s.size());
        Trie *root=new Trie();
        for(int i=0;i<n;i++){
            insert(root,contact[i]);
        }
        for(int i=1;i<=s.size();i++){
            string t=s.substr(0,i);
            Trie*a=search(root,t);
            if(a!=NULL){
                vector<string>v;
                find(a,t,v);
                ans[i-1]=v;
            }
            else
                ans[i-1]={"0"};
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
