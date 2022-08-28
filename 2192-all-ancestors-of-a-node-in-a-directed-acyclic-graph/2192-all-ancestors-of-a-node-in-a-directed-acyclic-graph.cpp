class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        queue<int> Q;
        vector<int> indegree(n);
        vector<vector<int>> adjList(n);
        vector<vector<int>> ans(n);
        vector<vector<bool>> isAncestor(n, vector<bool>(n, false)); // i is an ancestor of j

        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        for (int i=0; i<n; i++) {
            if (indegree[i] == 0)
                Q.push(i);
        }
        
        int size, cur;
        while (!Q.empty()) {
            size = Q.size();
            while (size-- > 0) {
                cur = Q.front(); Q.pop();
                for (int& nei : adjList[cur]) {
                    indegree[nei]--;
                    if (indegree[nei] == 0)
                        Q.push(nei);
                    isAncestor[cur][nei] = true;
                    
                    for (int k=0; k<n; k++) 
                        if (isAncestor[k][cur]) 
                            isAncestor[k][nei] = true; 
                }
            }
        }
        
        for (int cur=0; cur<n; cur++) 
            for (int j=0; j<n; j++) 
                if (isAncestor[j][cur])
                    ans[cur].push_back(j);
        
        return ans;
        
    }
};