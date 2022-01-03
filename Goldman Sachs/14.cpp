class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,mn=INT_MAX;
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                    mn=min(j-i+1,mn);
                    sum-=nums[i++];
                }
            }
            j++;
        }
        if(mn==INT_MAX)
            return 0;
        return mn;
    }
};
