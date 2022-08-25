class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        
        queue<int> Q;
        
        for (auto &p : pre) {
            adjList[p[0]].push_back(p[1]);
            // isReachable[p[0]][p[1]] = true;
            indegree[p[1]]++;
        }
        
        for (int i=0; i<numCourses; i++)
            if (indegree[i] == 0)
                Q.push(i);
        
        int cur;
        while (!Q.empty()) {
            cur = Q.front(); Q.pop();
                
            for (int& c : adjList[cur]) {
                isReachable[cur][c] = true;
                for (int i=0; i<numCourses; i++) {
                    if (isReachable[i][cur])
                        isReachable[i][c] = true;
                }
                
                indegree[c]--;
                if (indegree[c] == 0) 
                    Q.push(c);
            }
        }


        vector<bool> ans;
        for (auto &q : queries) 
            ans.push_back(isReachable[q[0]][q[1]]);
        
        return ans;
    }
};