#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(ull n) {
	    // code here
	    ull ugly[n];
	    ugly[0]=1;
	    ull i2=0,i3=0,i5=0;
	    for(ull i=1;i<n;i++){
	        ull t2=2*ugly[i2],t3=3*ugly[i3],t5=5*ugly[i5];
	        ugly[i]=min(t2,min(t3,t5));
	        if(ugly[i]==t2)
	            i2++;
	        if(ugly[i]==t3)
	            i3++;
	        if(ugly[i]==t5)
	            i5++;
	    }
	    return ugly[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
