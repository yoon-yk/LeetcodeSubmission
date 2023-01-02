class Solution {
public:
    /*
    [0,0,1,1,0,1,0,0,1,0]
    [1,1,0,1,1,0,1,1,1,0]
    [1,0,1,1,1,0,0,1,1,0]
    [0,1,1,0,0,0,0,1,0,1]
    [0,0,0,0,0,0,1,1,1,0]
    [0,1,0,1,0,1,0,1,1,1]
    [1,0,1,0,1,1,0,0,0,1]
    [1,1,1,1,1,1,0,0,0,0]
    [1,1,1,0,0,1,0,1,0,1]
    [1,1,1,0,1,1,0,1,1,0]]
    */
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i=0; i<grid.size(); ++i) 
            for (int j=0; j<grid[0].size(); ++j) 
                if (grid[i][j] == 0) ans += dfs(i, j, grid);
        return ans;
    }
    
    bool isValid (int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        return true;
    }
    
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(int i, int j, vector<vector<int>>& grid) {    
        
        if (i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1) return false;
        
        grid[i][j] = 1;
        int nr, nc;
        
        bool ans = true;
        for (auto &[r, c] : dir) {
            nr = i+r, nc = j+c;
            if (isValid(nr, nc, grid) && grid[nr][nc] == 0) {
                ans &= dfs(nr, nc, grid);
            }
        }
        return ans;
    }
};