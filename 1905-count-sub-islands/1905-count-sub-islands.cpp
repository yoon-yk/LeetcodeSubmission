class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int r = grid1.size(), c = grid1[0].size();
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (grid2[i][j] == 0) continue;
                ans += isSubIsland(grid1, grid2, i, j);
            }
        }
        
        return ans;
    }
    
    bool isSubIsland(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
        if (i < 0 || j < 0 || i >= g1.size() || j >= g1[0].size() || !g2[i][j]) 
            return true;
        
        if (!g1[i][j]) return false;
        
        g2[i][j] = 0;
        
        bool left = isSubIsland(g1, g2, i, j-1);
        bool right = isSubIsland(g1, g2, i, j+1);
        bool up = isSubIsland(g1, g2, i-1, j);
        bool down = isSubIsland(g1, g2, i+1, j);
        
        return (left && right && up && down);
    }
    
};