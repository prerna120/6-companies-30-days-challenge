#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        for(int i=1;i<=S.size()+1;i++){
            ans.push_back((i+'0'));
        }
        char c=S[0];
        int start=0;
        for(int i=1;i<S.size();i++){
            if(S[i]!=c){
                if(c=='D')
                    reverse(ans.begin()+start,ans.begin()+i+1);
                c=S[i];
                start=i;
            }
        }
        if(c=='D')
            reverse(ans.begin()+start,ans.end());
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
