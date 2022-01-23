class Solution {
public:
    
    bool check(vector<int>&weights,int mid,int days){
        int t=days,sum=0;
        for(int i=0;i<weights.size();i++){
            if((sum+weights[i])<=mid)
                sum+=weights[i];
            else{
                t--;
                sum=weights[i];
            }
            if(t<=0)
                return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(),mx=weights[0],sum=weights[0];
        for(int i=1;i<n;i++){
            mx=max(mx,weights[i]);
            sum+=weights[i];
        }
        int start=mx,end=sum,res=INT_MAX;
        while(start<=end){
            int mid=(start+end)/2;
            if(check(weights,mid,days)){
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return res;
    }
};
