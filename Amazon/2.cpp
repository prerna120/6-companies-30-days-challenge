class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int left=0,right=0,ans=0,n=arr.size();
        while(left<n){
            right=left;
            bool l=false,r=false;
            while(right<n-1 && arr[right]<arr[right+1]){
                right++;
                l=true;
            }
            while(right<n-1 && arr[right]>arr[right+1]){
                right++;
                r=true;
            }
            if(l && r)
                ans=max(ans,right-left+1);
            left=max(left+1,right);
        }
        return ans;
    }
};
