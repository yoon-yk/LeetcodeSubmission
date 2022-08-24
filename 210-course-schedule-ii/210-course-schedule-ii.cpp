class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> adjList(numCourses);
        vector<int> visited(numCourses);
        vector<int> ans;
        
        for (auto &p : pre) {
            adjList[p[1]].push_back(p[0]);
        }
        
        for (int i=0; i<numCourses; i++) 
            if (!dfs(i, adjList, visited, ans))
                return {};
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    bool dfs(int cur, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& ans) {
        
        if (visited[cur] == 2)
            return true;
        
        if (visited[cur] == 1)
            return false;
        
        visited[cur] = 1;
        
        for (int v : adjList[cur]) {
            if (!dfs(v, adjList, visited, ans))
                return false;
        }
        
        visited[cur] = 2;
        ans.push_back(cur);
        return true;
    }
};