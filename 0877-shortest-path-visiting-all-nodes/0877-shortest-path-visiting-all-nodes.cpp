class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1; // All nodes visited
        queue<pair<int, int>> Q; // <node, visited state>
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        
        for (int i = 0; i < n; ++i) {
            Q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int steps = 0;
        while (!Q.empty()) {
            int qSize = Q.size();
            
            while (qSize--) {
                auto [node, state] = Q.front(); Q.pop();
                
                if (state == target) return steps;
                
                for (const int& nei : graph[node]) {
                    int newState = state | (1 << nei);
                    
                    if (!visited[nei][newState]) {
                        visited[nei][newState] = true;
                        Q.push({nei, newState});
                    }
                }
            }
            
            ++steps;
        }
        
        return -1; // Unreachable
    }
};