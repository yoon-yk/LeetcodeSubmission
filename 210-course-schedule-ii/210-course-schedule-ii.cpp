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
            dfs(i, adjList, visited, ans);
        
        if (ans.size()!= numCourses)
            return {};
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    void dfs(int cur, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& ans) {
        
        if (visited[cur] == 2)
            return;
        
        if (visited[cur] == 1) {
            ans.push_back(-1);
            return;
        }    
        
        visited[cur] = 1;
        
        for (int v : adjList[cur]) {
            dfs(v, adjList, visited, ans);
        }
        
        visited[cur] = 2;
        ans.push_back(cur);
    }
};