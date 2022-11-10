class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nextCourses(numCourses);
        vector<int> indeg(numCourses);
        for (auto & pre : prerequisites) {
            nextCourses[pre[1]].push_back(pre[0]);
            indeg[pre[0]] ++;
        }
        
        queue<int> Q;
        for (int i=0; i<numCourses; i++) {
            if (indeg[i] == 0)
                Q.push(i);
        }
        
        int size;
        
        vector<int> ans;
        while (!Q.empty()) {
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                ans.push_back(cur);
                
                for (auto & next : nextCourses[cur]) {
                    indeg[next]--;
                    if (indeg[next] == 0)
                        Q.push(next);
                }
            }
        }
        
        if (ans.size() < numCourses) return {};
        return ans;
    }
};