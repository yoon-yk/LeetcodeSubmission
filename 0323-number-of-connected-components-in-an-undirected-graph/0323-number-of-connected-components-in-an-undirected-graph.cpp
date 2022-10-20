class Solution {
public:
    void dfs(int curN, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[curN] = true;
        
        for (auto& nei : adj[curN]) {
            if (!visited[nei]) 
                dfs(nei, adj, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for (auto & e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int cnt = 0;
        vector<bool> visited(n, false);
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                cnt ++;
                dfs(i, adj, visited);
            }
        }
        return cnt;
    }
};