class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        vector<vector<int>> adjList(n);
        
        for (auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1, labels, adjList, ans);
        return ans;
    }
    
    vector<int> dfs(int cur, int par, string & labels, vector<vector<int>>& adjList, vector<int>& ans) {
        
        vector<int> ret(26, 0); // frequnecy of subtrees;
        ++ret[labels[cur]-'a'];
        
        for (auto & nei : adjList[cur]) {
            if (nei == par) continue;
            auto child = dfs(nei, cur, labels, adjList, ans);
            for (int i=0; i<26; ++i) {
                ret[i] += child[i];
            }
        }
        
        ans[cur] = ret[labels[cur]-'a'];
        return ret;
    }
};