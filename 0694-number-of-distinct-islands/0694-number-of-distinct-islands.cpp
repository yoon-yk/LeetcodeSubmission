class Solution {
public:
    
    int m, n;
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    bool isInRange(int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        unordered_set<string> visitedSet;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!grid[i][j] || visited[i][j]) continue;
                visited[i][j] = true;
                string curPath = to_string(5);
                dfs(grid, i, j, curPath, visited);
                visitedSet.insert(curPath);
            }
        }

        
        return visitedSet.size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, string& curPath, vector<vector<bool>>& visited) {
        
        for (int d=0; d<4; d++) {
            int newI = i+dir[d], newJ = j+dir[d+1];
            if (isInRange(newI, newJ, m, n) && grid[newI][newJ] && !visited[newI][newJ]) {
                visited[newI][newJ] = true;
                curPath += to_string(d);
                dfs(grid, newI, newJ, curPath, visited);
            }
        }
        curPath += '.';

    }
};