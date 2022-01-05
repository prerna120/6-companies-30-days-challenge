// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    string solve(int &i,int n,string s){
        // cout<<i<<endl;
        int val=0;
        string t="",ans="";
        while(i<n){
            if(isdigit(s[i]))
                val=val*10+s[i]-'0';
            else if(s[i]=='['){
                i++;
                t=solve(i,n,s);
                while(val--){
                    ans+=t;
                }
                val=0;
            }
            else if(s[i]==']')
                return ans;
            else
                ans.push_back(s[i]);
            i++;
        }
        return ans;
    }

    string decodedString(string s){
        // code here
        int i=0,n=s.size();
        return solve(i,n,s);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
