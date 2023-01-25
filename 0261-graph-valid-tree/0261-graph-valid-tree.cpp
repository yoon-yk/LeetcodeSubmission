class Solution {
public:
    int unvisited = 0, visiting = 1, visited = 2;
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<bool> v(n, unvisited);
        for (auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        int ans = dfs(0, -1, adjList, v);
        return ans == n;
    }
    
    int dfs(int cur, int par, vector<vector<int>>& adjList, vector<bool>& v) {
        int nVisited = 1;
        v[cur] = visiting;
        
        for (auto & nei : adjList[cur]) {
            if (nei == par) continue;
            if (v[nei] != unvisited) return -1;
            nVisited += dfs(nei, cur, adjList, v);
        }
        v[cur] = visited;
        
        return nVisited;
    }
    
    
};