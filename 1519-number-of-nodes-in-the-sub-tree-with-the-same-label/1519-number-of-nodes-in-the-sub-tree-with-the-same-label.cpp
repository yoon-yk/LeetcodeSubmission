class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> nodeCounts(26);
        for (auto & e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n, 0);
        dfs(0, -1, adj, labels, ans, nodeCounts);
        return ans;
    }
    
    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string& labels, vector<int>& ans, vector<int>& nodeCounts) {
        
        int prev = nodeCounts[labels[node]-'a'];
        ++nodeCounts[labels[node]-'a'];
        
        for (auto & child : adj[node]) {
            if (child == parent) 
                continue;
            dfs(child, node, adj, labels, ans, nodeCounts);
        }
        ans[node] = nodeCounts[labels[node]-'a'] - prev;
        return nodeCounts;
    }
};