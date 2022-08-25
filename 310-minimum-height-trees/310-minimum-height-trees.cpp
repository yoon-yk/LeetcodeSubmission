class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (edges.empty()) return {0};
        
        vector<vector<int>> adjList (n);
        vector<int> degree(n);
        queue<int> Q;
        
        for (auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        // Leaf node has only one edge
        for (int i=0; i<n; i++) {
            if (degree[i] == 1) {
                Q.push(i);
                degree[i]--;
            }
        }
        
        int cur, cnt = n, size;
        while (!Q.empty() && (cnt > 2)) {
            size = Q.size();
            while (size--) {
                cur = Q.front(); Q.pop();
                cnt --;
            
                for (int& adj : adjList[cur]) {
                    degree[adj]--;
                    if (degree[adj] == 1){
                        Q.push(adj);
                    }
                }
            }

        }
        
        vector<int> ans;
        // while (!Q.empty() && n > 2 && degree[Q.front()] == 0) Q.pop();
        while (!Q.empty()) {
            ans.push_back(Q.front());
            Q.pop();
        }
        
        return ans;
    }
};