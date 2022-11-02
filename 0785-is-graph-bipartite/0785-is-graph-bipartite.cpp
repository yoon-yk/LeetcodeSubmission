class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        queue<int> Q;
        
        int size;
        int n = graph.size();
        int cnt = 0;
        int color = 1;
        vector<int> colored(n, -1);
        
        for (int i=0; i<n; i++) {
            if (colored[i] != -1) continue;
            cnt++;

            Q.push(i);
            colored[i] = color;

            while (!Q.empty()) {
                size = Q.size();
                while (size--) {
                    int cur = Q.front(); Q.pop();

                    for (int & nei : graph[cur]) {
                        if (colored[nei] == color) return false;
                        else if (colored[nei] != -1) continue;
                        colored[nei] = !color;
                        Q.push(nei);
                    }

                }
                color = !color;
            }   
        }
        
        return true;
    }
};