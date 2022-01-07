#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>characters(26,0);
		    string ans="";
		    int i=0,j=0;
		    while(i<A.size() && j<A.size()){
		        characters[A[j]-'a']++;
		        while(i<j && characters[A[i]-'a']>1){
		            i++;
		        }
		        if(characters[A[i]-'a']==1)
		            ans.push_back(A[i]);
		        else
		            ans.push_back('#');
		        j++;
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
