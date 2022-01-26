class Solution {
public:
    
    void swap(int i,int j,vector<int>&t){
        int temp=t[i];
        t[i]=t[j];
        t[j]=temp;
    }
    
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>z(n,0);
        unordered_map<int,vector<int>>um;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)
                    z[i]++;
                else
                    break;
            }
        }
        int swaps=0;
        for(int i=0;i<n-1;i++){
            int j=i;
            int req_zeroes=n-i-1;
            while(j<n && min(req_zeroes,z[j])!=req_zeroes){
                // cout<<z[j]<<endl;
                j++;
            }
            if(j==n)
                return -1;
            swaps+=(j-i);
            while(j>i){
                swap(j,j-1,z);
                j--;
            }
        }
        return swaps;
    }
};
