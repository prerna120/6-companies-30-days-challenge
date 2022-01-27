class Solution {
public:
    
    static bool comp(string a,string b){
        if(a.size()==b.size()){
            for(int i=0;i<a.size();i++){
                if(a[i]>b[i])
                    return true;
                else if(a[i]<b[i])
                    return false;
            }
        }
        return a.size()>b.size();
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[k-1];
    }
};
