class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // certain path every time
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans = max(ans, longestPath(i, j, matrix, dp));
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> dirs = {
        {-1, 0}, // up
        {1, 0}, // down
        {0, -1}, // left
        {0, 1} // right
    };
    
    bool valid(int i, int j, vector<vector<int>>& matrix){
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) 
            return false;
        return true;
    }
    
    int longestPath(int i, int j, vector<vector<int>>& matrix,
                   vector<vector<int>>& dp) {
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 1, nr, nc;
        for (auto & dir : dirs) {
            nr = i+dir[0], nc = j+dir[1];
            if (!valid(nr, nc, matrix) || matrix[nr][nc] <= matrix[i][j]) 
                continue;
            ans = max(ans, longestPath(nr, nc, matrix, dp)+1);
        }
        
        return dp[i][j] = ans;
    }
};