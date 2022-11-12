class Solution {
public:
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        
        int size = 0;
        grid[i][j] = 0;
        for (int d=0; d<4; d++) {
            size += dfs(grid, i+dir[d], j+dir[d+1]);
        }
        return size + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        
        return ans;
    }
};