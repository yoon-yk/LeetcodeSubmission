class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> ens;
        for(int i=0; i<speed.size(); i++) ens.push_back({efficiency[i], speed[i]});
        sort(ens.begin(), ens.end(), greater<pair<int, int>>());
        
        long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<ens.size(); i++) {
            q.push(ens[i].second);
            sum += ens[i].second;
            if(q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            res = max(res, sum*ens[i].first);
        }
        return res % (long)(1e9+7);
    }
};