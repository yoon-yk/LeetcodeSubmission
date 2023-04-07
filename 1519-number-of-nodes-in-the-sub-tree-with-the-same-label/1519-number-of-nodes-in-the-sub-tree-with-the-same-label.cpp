class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n), freq(26, 0);
        vector<vector<int>> adjList(n);
        
        for (auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1, labels, adjList, freq, ans);
        return ans;
    }
    
    void dfs(int cur, int par, string & labels, vector<vector<int>>& adjList, vector<int>& freq, vector<int>& ans) {
        
        int prev = freq[labels[cur]-'a'];
        ++freq[labels[cur]-'a'];
        
        for (auto & nei : adjList[cur]) {
            if (nei == par) continue;
            dfs(nei, cur, labels, adjList, freq, ans);
        }
        ans[cur] = freq[labels[cur]-'a'] - prev;
        
    }
};