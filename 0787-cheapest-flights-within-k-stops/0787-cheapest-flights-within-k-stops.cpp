class Solution {
public:
    using dpair = pair<int, int>;
    using tpair = pair<int, dpair>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<dpair>> adj(n);
        for (auto & e : flights)
            adj[e[0]].push_back(pair(e[1], e[2]));
        
        vector<int> stops(n, INT_MAX);
        
        priority_queue<tpair, vector<tpair>, greater<tpair>> pq;
        pq.push({0, {src, 0}});
    
        
        while (!pq.empty()) {
            auto [dist, nums] = pq.top(); pq.pop();
            auto& [curV, steps] = nums;
            
            if (steps > stops[curV] || steps > k+1) continue;
            
            stops[curV] = steps;
            if (curV == dst) return dist;
            
            for (auto & [nei, price] : adj[curV])
                pq.push({dist+price, {nei, steps+1}});
        }
        
        return -1;
        
    }
};