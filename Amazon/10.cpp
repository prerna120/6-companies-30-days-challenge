#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    static bool comp(char a,char b){
        unordered_map<char,int>map;
        map['!']=1,map['#']=2,map['$']=3,map['%']=4,map['&']=5
        ,map['*']=6,map['@']=7,map['^']=8,map['~']=9;
        return map[a]<map[b];
    }

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    sort(nuts,nuts+n,comp);
	    sort(bolts,bolts+n,comp);
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
