class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto & e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        int rest = n;
        long long ans;
        queue<int> Q;
        vector<bool> visited(n, false);
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                Q.push(i);
                int cnt = 0 ;
                visited[i] = true;
                
                while (!Q.empty()) {
                    int cur = Q.front(); Q.pop();
                    cnt ++;
                    for (auto & nei : adjList[cur]) {
                        if (!visited[nei]) {
                            Q.push(nei);
                            visited[nei] = true;
                        }
                    }
                }
                
                rest -= cnt;
                ans += ((long long)cnt * rest);
            }
        }
        
        return ans;
    }
};