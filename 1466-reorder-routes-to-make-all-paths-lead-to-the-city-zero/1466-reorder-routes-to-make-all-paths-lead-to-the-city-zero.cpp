class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n, false);
        for (auto & c : connections) {
            adjList[c[0]].push_back(c[1]);
            adjList[c[1]].push_back(-c[0]);
        }
        return dfs(0, adjList, visited);
    }
    
    int dfs(int cur, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[cur] = true;
        int next, ans = 0;
        for (auto & nei : adjList[cur]) {
            next = abs(nei);
            if (visited[next]) continue;
            if (nei > 0) ++ans;
            ans += dfs(next, adjList, visited);
        }
        return ans;
    }
};