class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses); // list of courses you can take after this course 
        vector<int> indeg(numCourses);
        queue<int> Q;
        
        for (auto& pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        for (int i=0; i<numCourses; i++) {
            if (indeg[i] == 0)
                Q.push(i);
        }
        
        int cnt = numCourses;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            cnt--;
            
            for (int & nei : adjList[cur]) {
                if (--indeg[nei] == 0)
                    Q.push(nei);
            }
        }
        
        return (cnt == 0);
    }
};