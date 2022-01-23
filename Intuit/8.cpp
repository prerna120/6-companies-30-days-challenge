class Solution {
public:
    
    int distance(vector<int>&a,vector<int>&b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0,n=points.size();
        vector<unordered_map<int,int>>um(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)
                    continue;
                int dist=distance(points[i],points[j]);
                um[i][dist]++;
            }
        }
        for(int i=0;i<n;i++){
            for(auto &it:um[i]){
                int c=it.second;
                ans+=c*(c-1);
            }
        }
        return ans;
    }
};
