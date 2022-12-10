class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indeg(numCourses);
        for (auto & pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        
        queue<int> Q;
        for (int i=0; i<numCourses; ++i) {
            if (indeg[i] == 0)
                Q.push(i);
        }
        
        int cnt = numCourses;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            cnt--;
            for (auto & next : adjList[cur]) {
                if (--indeg[next] == 0)
                    Q.push(next);
            }
        }
        
        return (cnt == 0);
    }
    
    
};