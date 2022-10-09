class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1)
            return 0;
        
        int n = graph.size();
        int endingMask = (1 << n) -1;
        vector<vector<bool>> seen(n, vector<bool>(endingMask));
        queue<vector<int>> q;
        
        for (int i=0; i<n; i++) {
            q.push({i, 1<<i});
            seen[i][1<<i] = true;
        }
        
        int steps = 0, size;
        while (!q.empty()) {
            queue<vector<int>> nextQ;
            size = q.size();
            while (size--) {
                vector<int> currPair = q.front(); q.pop();
                int node = currPair[0];
                int mask = currPair[1];
                
                for (int& neighbor : graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    if (nextMask == endingMask)
                        return 1 + steps;
                    
                    if (!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        nextQ.push({neighbor, nextMask});
                    }
                }
            }
            
            steps++;
            q = nextQ;
        }
        
        return -1;
    }
};