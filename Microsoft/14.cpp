// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        D=abs(D);
        int n=1;
        while(D>0){
            D-=n;
            n++;
        }
        if(D==0)
            return n-1;
        if(D%2==0)
            return n-1;
        if(D%2!=0 && n%2!=0)
            return n;
        return n+1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
