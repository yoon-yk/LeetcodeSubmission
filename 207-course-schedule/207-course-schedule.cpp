class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        if (pre.empty()) return true;
        
        vector<vector<int>> adjList (numCourses);
        vector<int> visited(numCourses, 0); // 0 (unvisited), 1 (visiting), 2 (visited)
        
        for (auto& p : pre) {
            adjList[p[0]].push_back(p[1]);    
        }
        
        for (int i=0; i<numCourses; i++){
            if (!dfs(i, adjList, visited))
                return false;
        }

        return true;
    }
    
    bool dfs(int cur, vector<vector<int>>& adjList, vector<int>& visited) {
        
        if (visited[cur] == 1) return false;
        if (visited[cur] == 2) return true; 
        
        visited[cur] = 1;
        
        for (auto & v : adjList[cur]){
            if (!dfs(v, adjList, visited))
                return false;
        }
        
        visited[cur] = 2;
        
        return true;        
    }
};