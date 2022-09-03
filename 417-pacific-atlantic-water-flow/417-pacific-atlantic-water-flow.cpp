class Solution {
public:

    vector<int> dir = {-1, 0, 1, 0, -1};
    vector<vector<int>> ans;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rlim = heights.size(), clim = heights[0].size();
        vector<vector<bool>> pacificVis(rlim, vector<bool>(clim));
        vector<vector<bool>> atlanticVis(rlim, vector<bool>(clim));
        
        for (int i=0; i<rlim; i++){
            dfs(i, 0, -1, heights, pacificVis, atlanticVis);
            dfs(i, clim-1, -1, heights, atlanticVis, pacificVis);
        }
        
        
        for (int i=0; i<clim; i++){
            dfs(0, i, -1, heights, pacificVis, atlanticVis);
            dfs(rlim-1, i, -1, heights, atlanticVis, pacificVis);
        }        
        
        return ans;
    }
    
    void dfs(int r, int c, int prev, vector<vector<int>>& heights, vector<vector<bool>>& mvis, vector<vector<bool>>& cvis) {
        
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || mvis[r][c] || heights[r][c] < prev)
            return;
        
        mvis[r][c] = true;
        if (cvis[r][c])
            ans.push_back({r, c});
        
        for (int d = 0; d < 4; d++) {
            dfs(r+dir[d], c+dir[d+1], heights[r][c], heights, mvis, cvis);
        }
    }
};