class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
        vector<vector<int>> adjList(numCourses);
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        
        queue<int> Q;
        
        for (auto &p : pre) {
            adjList[p[0]].push_back(p[1]);
        }
        
        for (int i=0; i<numCourses; i++) {
            Q.push(i);
            
            int cur;
            while(!Q.empty()) {
                cur = Q.front(); Q.pop();
                
                for (int& c : adjList[cur]) {
                    if (isReachable[i][c]) continue;
                    isReachable[i][c] = true;
                    Q.push(c);
                }
            }
        }

        vector<bool> ans;
        for (auto &q : queries) 
            ans.push_back(isReachable[q[0]][q[1]]);
        
        return ans;
    }
};