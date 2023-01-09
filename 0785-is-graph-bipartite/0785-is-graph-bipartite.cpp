class Solution {
public:
    int red = 1, blue = 0;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> Q;
        vector<int> colors(n, -1);
        for (int i=0; i<n; ++i) {
            Q.push(i);
            if (colors[i] == -1) colors[i] = red;
            
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
            
                for (int & nei : graph[cur]) {
                    if (colors[cur] == colors[nei]) 
                        return false;
                    if (colors[nei] == -1) {
                        colors[nei] = !colors[cur];
                        Q.push(nei);
                    }
                }
            }
            
        }
        return true;
    }
};