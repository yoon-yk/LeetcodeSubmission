class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        for (const auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(src);
        
        int cur;
        while (!q.empty()) {
            cur = q.front(); q.pop();
            if (cur == des)
                return true;
            visited[cur] = true;
            
            for (int& next : graph[cur]) {
                if (!visited[next]) {
                    q.push(next);
                }
            }
        }
        
        return false;
    }
};