class Solution {
public:
    vector<int> minCost;
    vector<vector<pair<int, int>>> adjList;
    
    void dfs(int idx, int curCost) {
        if (minCost[idx] <= curCost) return;
        minCost[idx] = curCost;
        
        sort(adjList[idx].begin(), adjList[idx].end());
        for (auto & [next, cost] : adjList[idx]) {
            dfs(next, curCost+cost);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        minCost.resize(n+1, INT_MAX);
        adjList.resize(n+1);
        
        for (auto & time : times) {
            int src = time[0], dst = time[1], cost = time[2];
            adjList[src].push_back({dst, cost});
        }
        
        dfs(k, 0);
        
        int ans = *max_element(minCost.begin()+1, minCost.end());
        
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};