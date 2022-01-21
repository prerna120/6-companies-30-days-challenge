//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        if(N.size()<4)
            return "-1";
        string ans=N.substr(0,N.size()/2);
        int ind=-1;
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i]<ans[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1)
            return "-1";
        int mx=ind;
        for(int i=ans.size()-1;i>ind;i--){
            if(ans[mx]<ans[i]){
                mx=i;
                break;
            }
        }
        char c=ans[mx];
        ans[mx]=ans[ind];
        ans[ind]=c;
        reverse(ans.begin()+ind+1,ans.end());
        // cout<<ans<<endl;
        string t=ans;
        reverse(t.begin(),t.end());
        if(N.size()%2!=0)
            ans.push_back(N[N.size()/2]);
        ans+=t;
        if(ans==N)
            return "-1";
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
