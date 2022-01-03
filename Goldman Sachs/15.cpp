 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2!=0)
            return false;
        int p=nums.size()/2;
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
            int no=nums[i]%k;
            int find=k-no;
            if(no==0)
                find=0;
            if((um.find(find)!=um.end() && um[find]>0))
                p--,um[find]--;
            else
                um[no]++;
        }
        return p==0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
