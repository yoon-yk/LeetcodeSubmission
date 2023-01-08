class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        
        vector<set<pair<int, int>>> adjList(n+1);
        for (auto & time : times) {
            adjList[time[0]].insert({time[2], time[1]});
        }
        
        queue<pair<int, int>> Q;
        Q.push({k, 0});
        vector<int> minTime(n+1, INT_MAX);
        minTime[k] = minTime[0] = 0;
        while (!Q.empty()) {
            auto [v, t] = Q.front(); Q.pop();
            
            for (auto & [cost, nv] : adjList[v]) {
                if (t+cost >= minTime[nv]) continue;
                minTime[nv] = t+cost;
                Q.push({nv, minTime[nv]});
            }
        }
        ans = *max_element(minTime.begin()+1, minTime.end());
        return ans == INT_MAX ? -1 : ans;
    }
};