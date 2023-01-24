class Solution {
public:
    
    int ans = 0;
    
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited
            (grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                dfs(grid, i, j, visited);
                break;
            }
        }
        return ans;
    }
    
    bool dfs(vector<vector<int>>& grid, int i, int j, 
            vector<vector<bool>>& visited) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() 
            || grid[i][j] == 0)
            return true;
        if (visited[i][j]) return false;

        visited[i][j] = true;
        int up = dfs(grid, i-1, j, visited);
        int down = dfs(grid, i+1, j, visited);
        int left = dfs(grid, i, j-1, visited);
        int right = dfs(grid, i, j+1, visited);
        
        ans += up + down + left + right;
        
        return false;    
    }
};