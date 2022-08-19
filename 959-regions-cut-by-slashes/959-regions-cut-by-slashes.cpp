class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int newGridSize;
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        newGridSize = n*3;
        vector<vector<bool>> newGrid(newGridSize, vector<bool>(newGridSize, 1));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '/') {
                    newGrid[i*3][j*3+2] = 0;
                    newGrid[i*3+1][j*3+1] = 0;
                    newGrid[i*3+2][j*3] = 0;
                    
                } else if (grid[i][j] == '\\') {
                    newGrid[i*3][j*3] = 0;
                    newGrid[i*3+1][j*3+1] = 0;
                    newGrid[i*3+2][j*3+2] = 0;
                }
            }
        }
        
        int ans = 0;
        for (int i=0; i<newGridSize; i++) {
            for (int j=0; j<newGridSize; j++) {
                if (newGrid[i][j] == 1)
                    ans += dfs(newGrid, i, j);
            }
        }
        
        return ans;
    }
    
    
    int dfs(vector<vector<bool>>& grid, int i, int j) {
        
        if (i < 0 || i >= newGridSize || j < 0 || j >= newGridSize || grid[i][j] == 0) 
            return 0;
        
        grid[i][j] = 0;
        
        for (int n=0; n< 4; n++) {
            dfs(grid, i+dir[n], j+dir[n+1]);
        }
        
        return 1;
    }
};