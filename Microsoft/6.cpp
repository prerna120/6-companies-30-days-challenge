//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void combinations(int a[],int N,string op,int ind,unordered_map<int,vector<char>>&um,vector<string>&ans){
        if(ind==N){
            ans.push_back(op);
            return;
        }
        for(int i=0;i<um[a[ind]].size();i++){
            // cout<<1;
            combinations(a,N,op+um[a[ind]][i],ind+1,um,ans);
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string>ans;
        unordered_map<int,vector<char>>um;
        um[2]={'a','b','c'};
        um[3]={'d','e','f'};
        um[4]={'g','h','i'};
        um[5]={'j','k','l'};
        um[6]={'m','n','o'};
        um[7]={'p','q','r','s'};
        um[8]={'t','u','v'};
        um[9]={'w','x','y','z'};
        combinations(a,N,"",0,um,ans);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
