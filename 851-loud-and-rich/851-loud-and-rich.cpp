class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n);
        vector<vector<int>> adjList(n);
        vector<int> indeg(n, 0);
        queue<int> Q;
        
        for (int i=0; i<n; i++)
            ans[i] = i;
        
        for (auto &r : richer){
            adjList[r[1]].push_back(r[0]);
        }

        int cur;
        for (int i=0; i<n; i++)
            dfs(i, adjList, quiet, ans);
        
        return ans;
        
    }
    
    int dfs (int cur, vector<vector<int>>& adjList, vector<int>& quiet, vector<int>& ans) {
        
        if (ans[cur] != cur)
            return ans[cur];
        
        int neiQ, minQ = cur;
        
        for (int &nei : adjList[cur]) {
            neiQ = dfs(nei, adjList, quiet, ans);
            if (quiet[neiQ] < quiet[minQ])
                minQ = neiQ;
        }
        
        return ans[cur] = minQ; 
    }
};