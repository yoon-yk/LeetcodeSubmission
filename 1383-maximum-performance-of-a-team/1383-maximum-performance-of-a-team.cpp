class Solution {
public:
    
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> maxEffList(n);
        for (int i = 0; i < n; ++i)
            maxEffList[i] = {efficiency[i], speed[i]};
        sort(rbegin(maxEffList), rend(maxEffList));
        
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; // speed min heap
        
        for(auto & [e, s]: maxEffList){
            pq.emplace(s);
            sumS += s;
            
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            
            res = max(res, sumS * e);
        }
        
        return res % MOD;
    }
};