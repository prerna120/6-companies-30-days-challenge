#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans=new int[2];
        int ans_xor=0;
        
        for(int i=0;i<n;i++){
            ans_xor^=(i+1);
            ans_xor^=arr[i];
        }
        int rightmost_setbit=-1,temp=ans_xor;
        while(temp){
            temp=temp>>1;
            rightmost_setbit++;
        }
        int find_set=1<<rightmost_setbit;
        int set1=0,set2=0;
        for(int i=0;i<n;i++){
            if(arr[i]&find_set)
                set1^=arr[i];
            if(!(arr[i]&find_set))
                set2^=arr[i];
            if((i+1)&find_set)
                set1^=(i+1);
            if(!((i+1)&find_set))
                set2^=(i+1);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==set1 || arr[i]==set2)
                ans[0]=arr[i];
        }
        if(ans[0]==set1)
            ans[1]=set2;
        else
            ans[1]=set1;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
