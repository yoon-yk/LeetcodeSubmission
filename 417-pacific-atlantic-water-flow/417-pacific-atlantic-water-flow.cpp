class Solution {
public:

    vector<int> dir = {-1, 0, 1, 0, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rlim = heights.size(), clim = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<char>> vis(rlim, vector<char>(clim));
        
        for (int i=0; i<rlim; i++){
            dfs(i, 0, -1, heights, vis, 1, ans);
            dfs(i, clim-1, -1, heights, vis, 2, ans);
        }
        
        
        for (int i=0; i<clim; i++){
            dfs(0, i, -1, heights, vis, 1, ans);
            dfs(rlim-1, i, -1, heights, vis, 2, ans);
        }        
        
        return ans;
    }
    
    void dfs(int r, int c, int prev, vector<vector<int>>& heights, vector<vector<char>>& vis, int mark, vector<vector<int>>& ans) {
        
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || (vis[r][c] & mark) == mark || heights[r][c] < prev)
            return;
        
        vis[r][c] |= mark;
        if (vis[r][c] == 3)
            ans.push_back({r, c});
        
        
        for (int d = 0; d < 4; d++)
            dfs(r+dir[d], c+dir[d+1], heights[r][c], heights, vis, mark, ans);
    }
};