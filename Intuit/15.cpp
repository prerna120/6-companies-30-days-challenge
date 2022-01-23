class Solution {
public:
    
    bool check(long long int k,vector<int>&piles,int h){
        for(int i=0;i<piles.size();i++){
            h-=piles[i]/k;
            if(piles[i]%k!=0)
                h--;
            if(h<0)
                return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=piles[0],n=piles.size();
        for(int i=0;i<n;i++){
            mx=max(mx,piles[i]);
        }
        long long int l=1,r=mx,k=-1;
        while(l<=r){
            long long int mid=l+(r-l)/2;
            if(check(mid,piles,h))
                k=mid,r=mid-1;
            else
                l=mid+1;
        }
        return k;
    }
};
