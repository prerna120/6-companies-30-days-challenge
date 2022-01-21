/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int bs1(int target, MountainArray MountainArr,int start,int end){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(MountainArr.get(mid)==target)
                return mid;
            else if(MountainArr.get(mid)<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    
    int bs2(int target, MountainArray MountainArr,int start,int end){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(MountainArr.get(mid)==target)
                return mid;
            else if(MountainArr.get(mid)>target)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &MountainArr) {
        int n=MountainArr.length(),ind=-1,start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid!=0 && mid!=n-1 && MountainArr.get(mid)>MountainArr.get(mid+1)
              && MountainArr.get(mid)>MountainArr.get(mid-1)){
                ind=mid;
                break;
            }
            else if(mid==0 && MountainArr.get(0)>MountainArr.get(1)){
                ind=0;
                break;
            }
            else if(mid==n-1 && MountainArr.get(n-1)>MountainArr.get(n-2)){
                ind=n-1;
                break;
            }
            else if(mid!=n-1 && MountainArr.get(mid)<MountainArr.get(mid+1))
                start=mid+1;
            else if(mid!=0 && MountainArr.get(mid)<MountainArr.get(mid-1))
                end=mid-1;
        }
        int l=-1,r=-1;
        if(MountainArr.get(0)<=target && MountainArr.get(ind)>=target)
            l=bs1(target,MountainArr,0,ind);
        if(l!=-1)
            return l;
        if(MountainArr.get(ind+1)>=target && MountainArr.get(n-1)<=target)
            r=bs2(target,MountainArr,ind+1,n-1);
        if(r==-1)
            return -1;
        return r;
    }
};
