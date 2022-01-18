#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    
    bool check(string s1,string s2){
        for(int i=0;i<min(s1.size(),s2.size());i++){
            if(s1[i]>s2[i])
                return true;
            else if(s1[i]<s2[i])
                return false;
        }
        return s1.size()>s2.size();
    }
    
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>um;
        for(int i=0;i<n;i++){
            um[arr[i]]++;
        }
        string s="";
        int mx=0;
        for(auto it:um){
            if((it.second==mx && check(s,it.first)) || (it.second>mx)){
                mx=it.second;
                s=it.first;
            }
        }
        string t=to_string(mx);
        vector<string>ans;
        ans.push_back(s);
        ans.push_back(t);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
