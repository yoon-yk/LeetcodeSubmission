class Solution {
public:
    vector<int> minCost;
    vector<vector<pair<int, int>>> adjList;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        minCost.resize(n+1, INT_MAX);
        adjList.resize(n+1);
        
        for (auto & time : times) {
            int src = time[0], dst = time[1], cost = time[2];
            adjList[src].push_back({cost, dst});
        }
        
        for (auto & list : adjList) {
            sort(list.begin(), list.end());
        }
        
        minCost[k] = 0;
        
        queue<pair<int, int>> Q;
        Q.push({0, k});
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int curIdx = cur.second, curCost = cur.first;
            for (auto & [cost, next] : adjList[curIdx]) {
                if (minCost[next] <= curCost + cost) 
                    continue;
                minCost[next] = curCost + cost;
                Q.push({curCost+cost, next});
            }
            
        }
        
        int ans = *max_element(minCost.begin()+1, minCost.end());
        
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};