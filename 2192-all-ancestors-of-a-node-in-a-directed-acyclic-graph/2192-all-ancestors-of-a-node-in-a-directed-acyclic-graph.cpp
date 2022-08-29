class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjList(n);
        vector<vector<int>> ans(n);

        for (auto& e : edges) 
            adjList[e[0]].push_back(e[1]);
        
        for (int i=0; i<n; i++) 
            dfs(i, i, ans, adjList);
        
        return ans;
    }
    
    void dfs(int root, int curr, vector<vector<int>>& ans, vector<vector<int>>& adjList) {
        for (auto& ch : adjList[curr]) {
            if (ans[ch].empty() || ans[ch].back()!=root) {
                ans[ch].push_back(root);
                dfs(root, ch, ans, adjList);
            }
        }
    }
};