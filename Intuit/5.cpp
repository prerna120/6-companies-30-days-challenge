class Solution {
public:
    
    bool check(int mx,vector<int>&nums,int m){
        int c=0,n=nums.size();
        for(int i=0;i<n;i++){
            c+=nums[i];
            if(nums[i]>mx)
                return false;
            if(c>mx)
                c=nums[i],m--;
            if(m==0)
                return false;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sum=0,mn=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mn=min(mn,nums[i]);
        }
        int l=mn,h=sum,ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(mid,nums,m)){
                h=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
