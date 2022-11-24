class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // make adj list with counting indegrees
        // put into q those have zero indegree
        
        vector<vector<int>> adjList(n+1);
        vector<int> indeg(n+1, 0);
        for (auto & r : relations) {
            adjList[r[0]].push_back(r[1]);
            indeg[r[1]]++;
        }
        
        queue<int> Q;
        for (int i=1; i<=n; i++)
            if (indeg[i] == 0)
                Q.push(i);
        
        int notTaken = n;
        int days = 0;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--){
                auto cur = Q.front(); Q.pop();
                notTaken --;
                
                for (int& nei : adjList[cur]) {
                    indeg[nei] --;
                    if (indeg[nei] == 0) {
                        Q.push(nei);
                    }
                }
            }
            days ++;
        }
        // q
        // BFS - topological sorting 
        // days ++
        
        return (notTaken > 0)? -1 : days;
        // if visited node < n
        // return -1
        // else return days;
    }
};