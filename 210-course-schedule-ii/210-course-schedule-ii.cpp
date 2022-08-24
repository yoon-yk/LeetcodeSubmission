class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adjList(numCourses);
        vector<bool> visited(numCourses, false);
        vector<int> indegree(numCourses);
        queue<int> Q;
        
        vector<int> ans;
        
        for (auto &p : pre) {
            adjList[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        int cnt = 0;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                Q.push(i);
                cnt++;
                visited[i] = true;
            }
        }
        if (Q.empty()) return {};
        
        int cur;
        while (!Q.empty()) {
            cur = Q.front(); Q.pop();
            ans.push_back(cur);
            
            for (int &nei : adjList[cur]) {
                indegree[nei]--;
                if (!visited[nei] && indegree[nei] == 0) {
                    Q.push(nei);
                    cnt++;
                    visited[nei] = true;
                }
            }
        }
        
        if (cnt < numCourses) return {};
        return ans;
    }
};