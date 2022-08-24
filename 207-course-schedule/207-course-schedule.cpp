class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        
        vector<bool> visited(numCourses, false);
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        queue<int> Q;
        
        for (auto &pre : prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
            indegrees[pre[1]]++;
        }
        
        for (int i=0; i<numCourses; i++){
            if (indegrees[i] == 0) {
                Q.push(i);
                visited[i] = true;
            }
        }
        
        int cur;
        int cnt = numCourses;
        while (!Q.empty()) {
            cur = Q.front(); Q.pop();
            numCourses--;
            
            for (int &i : adjList[cur]) {
                if (!visited[i] && --indegrees[i] == 0) {
                    visited[i] = true;
                    Q.push(i);
                }
                
            }
        }
            
        return (numCourses == 0);
    }
};