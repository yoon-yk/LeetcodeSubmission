class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjList(n);
        vector<vector<int>> ans(n);
        for (auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
        }
        
        for (int i=0; i<n; i++) {
            vector<bool> visited(n, false);
            visited[i] = true;
            dfs(i, i, visited, adjList, ans);
        }
        
        return ans;
    }
    
    void dfs(int root, int cur, vector<bool> &visited, vector<vector<int>>& adjList, vector<vector<int>>& ans) {
        
        if (cur!=root) ans[cur].push_back(root);
        
        for (auto & nei : adjList[cur]) {
            if (visited[nei]) continue;
            visited[nei] = true;
            dfs(root, nei, visited, adjList, ans);
        }
    }    
};