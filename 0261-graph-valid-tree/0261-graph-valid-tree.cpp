class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        stack<int> st;
        vector<vector<int>> adjList(n);
        vector<int> visited(n, false);
        
        for (auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        int cnt = 0;
        return dfs (0, -1, adjList, visited, cnt) && (cnt == n);
    }
    
    bool dfs(int node, int parent, vector<vector<int>>& adjList, vector<int>& visited, int& cnt) {
        
        if (visited[node]) return false;
        visited[node] = true;
        cnt ++;
        
        for (int & nei : adjList[node]) {
            if (parent == nei) continue;
            if (!dfs(nei, node, adjList, visited, cnt)) return false;
        }
        
        return true;
    }
    
    
            
};