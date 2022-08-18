class Solution {
public:
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return cnt;
    }
    
    void dfs(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';
        
        for (int i=0; i<4; i++) {
            dfs(r+dir[i], c+dir[i+1], grid);
        }
    }
};