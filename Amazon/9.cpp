// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool check(int i,int j,vector<vector<int>>&mat,int row[]){
        int val=mat[i][j];
        if(val>0){
            if(row[val]>0)
                return false;
            row[val]++;
        }
        return true;
    }
    
    bool check_square(int i,int j,vector<vector<int>>&mat){
        int arr[10]={0};
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(!check(i+k,j+l,mat,arr))
                    return false;
            }
        }
        return true;
    }

    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0;i<9;i++){
            int row[10]={0},col[10]={0};
            for(int j=0;j<9;j++){
                if(!check(i,j,mat,row) || !check(j,i,mat,col))
                    return 0;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!check_square(3*i,3*j,mat))
                    return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
