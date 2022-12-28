class Solution {
public:
    /*
    [0,1,0]
    [0,0,0]
    [0,0,1]
    
    [1,1,1,1,1]
    [1,0,0,0,1]
    [1,0,1,0,1]
    [1,0,0,0,1]
    [1,1,1,1,1]
    
    
    [1,1,1,1,1]
    [0,0,0,0,0]
    [0,0,0,0,0]
    [1,1,1,1,1]
    [1,1,1,1,1]
    
    */
    vector<int> dir = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> Q;
    void dfs(vector<vector<int>>& grid, int i, int j, int color) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1) return;
        
        grid[i][j] = color;
        if (color == 2) Q.push({i, j});
        for (int d=0; d<4; ++d)
            dfs(grid, i+dir[d], j+dir[d+1], color);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int color = 2;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {dfs(grid, i, j, color); color<<=1;}
            }
        }
        
        int nR, nC, level = 0;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto [r, c] = Q.front(); Q.pop();
                int curColor = grid[r][c];
                
                for (int d=0; d<4; ++d) {
                    nR = r+dir[d], nC = c+dir[d+1];
                    if (nR<0 || nC<0 || 
                        nR>=grid.size() || nC>=grid[0].size() ||
                        (grid[nR][nC] & curColor))
                        continue;
                    Q.push({nR, nC});
                    grid[nR][nC] |= curColor;
                    if (grid[nR][nC] == 6 )
                        return level;
                }
            }
            ++level;
        }
        
        return 0;
    }
};