class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> ens;
        for(int i=0; i<speed.size(); i++) ens.emplace_back(efficiency[i], speed[i]);
        sort(ens.begin(), ens.end(), greater<pair<int, int>>()); // Sort by efficiency
        
        long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> speedQ; // Sort by increasing speed
        
        for (auto& [e, s] : ens) {
            speedQ.push(s);
            sum += s;
            if (speedQ.size() > k) {
                sum -= speedQ.top();
                speedQ.pop();
            }
            res = max(res, sum*e);
        }
        
        return res % (long)(1e9+7);
    }
};