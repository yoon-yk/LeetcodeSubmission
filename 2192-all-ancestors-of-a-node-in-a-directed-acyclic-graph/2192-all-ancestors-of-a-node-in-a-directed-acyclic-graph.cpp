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
            // cout << "size" << size << endl;
            while (size-- > 0) {
                cur = Q.front(); Q.pop();
                // cout << cur << endl;
                for (int& nei : adjList[cur]) {
                    indegree[nei]--;
                    // cout << "is" << isAncestor[cur][nei] << endl;
                    if (indegree[nei] == 0){
                        Q.push(nei);
                        // cout << "inserted" << endl;
                    }
                    isAncestor[cur][nei] = true;
                    
                    for (int k=0; k<n; k++) {
                        // cout << "test" << k << endl;

                        if (isAncestor[k][cur]) {
                            // cout << k << cur << endl;
                            isAncestor[k][nei] = true; 
                        }
                    }
                }
            }
            // cout << "Q" << Q.size() << endl;
        }

        
        for (int j=0; j<n; j++) {
            for (int cur=0; cur<n; cur++) {
                if (isAncestor[j][cur])
                    ans[cur].push_back(j);
            }
        }
        
        return ans;
        
    }
};