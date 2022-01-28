class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>engineer;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            engineer.push_back({efficiency[i],speed[i]});
        }
        sort(engineer.begin(),engineer.end());
        long long int sum=0,ans=0;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=n-1;i>=0;i--){
            if(q.size()==k){
                sum=sum-q.top();
                q.pop();
            }
            sum=(sum+engineer[i].second);
            int e=engineer[i].first;
            q.push(engineer[i].second);
            ans=max(ans,(sum*e));
        }
        return ans%mod;
    }
};
