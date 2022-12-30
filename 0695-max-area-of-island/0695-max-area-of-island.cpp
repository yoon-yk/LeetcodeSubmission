class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
            return 0;
        
        grid[i][j] = 9;
        int ans = 1;
        for (int d=0; d<4; ++d) {
            ans += dfs(grid, i+dir[d], j+dir[d+1]);
        }
        return ans;
    }
};