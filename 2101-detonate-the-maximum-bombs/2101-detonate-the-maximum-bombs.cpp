class Solution {
public:
    /*BACKTRACKING VISITED 관리랑 헷갈리지 마!!!!!!!!1*/
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), x1, x2, y1, y2, r1, r2;
        double dist;
        vector<vector<int>> adjList(n);
        for (int i=0; i<bombs.size(); ++i) {
            for (int j=0; j<i; ++j) {
                auto& b1 = bombs[i], b2 = bombs[j];
                x1 = b1[0], y1 = b1[1], r1 = b1[2];
                x2 = b2[0], y2 = b2[1], r2 = b2[2];
                dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
                if (dist <= r2) 
                    adjList[j].push_back(i);
                if (dist <= r1) 
                    adjList[i].push_back(j);
            }
        }
        
        int ans = 0;
        for (int i=0; i<n; ++i) {
            vector<bool> visited(n, false);
            visited[i] = true;
            ans = max(ans, dfs(i, adjList, visited));
        }
        
        return ans;
        
    }
    
    int dfs(int idx, vector<vector<int>>& adjList, vector<bool>& visited) {
        
        int ans = 0;
        
        for (auto & nei : adjList[idx]) {
            if (visited[nei]) continue;
            visited[nei] = true;
            ans += dfs(nei, adjList, visited);
        }
        return ans + 1;
    }
};