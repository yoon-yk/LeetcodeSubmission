class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        // make adjList
            // if one can reach the other's center, 
            // it's a neighbor to one 
        
        int n = bombs.size();
        vector<vector<int>> adjList(n);
        
        int cX, cY, nX, nY;
        long dist, cR, nR;
        for (int i=0; i<n; i++) {
            cX = bombs[i][0], cY = bombs[i][1], cR = bombs[i][2];
            
            for (int j=i+1; j<n; j++) {
                nX = bombs[j][0], nY = bombs[j][1], nR = bombs[j][2];
                dist = pow(cX-nX, 2) + pow(cY-nY, 2);
                if (dist <= cR*cR) 
                    adjList[i].push_back(j);
                
                if (dist <= nR*nR) 
                    adjList[j].push_back(i);
            
            }
        }
        
        // do dfs
        int ans = 1;
        vector<bool> visited(n, false);
        for (int i=0; i<n; i++) {
            ans = max(ans, dfs(i, adjList, visited));
            fill(visited.begin(), visited.end(), false);
        }
        
        // return maximum result
        return ans;
    }
    
    int dfs(int idx, vector<vector<int>>& adjList,
           vector<bool>& visited) {
        
        int ans = 1;
        
        visited[idx] = true;
        
        for (int& nei : adjList[idx]) {
            if (visited[nei]) continue;
            ans += dfs(nei, adjList, visited);
        }
        
        return ans;
    }
};



