class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int ans = 0;
        for (int i=0; i<matrix.size(); ++i) 
            for (int j=0; j<matrix[0].size(); ++j) 
                ans = max(ans, dfs(i, j, matrix, dp));
        
        return ans;
    }
    
    bool isValid(int r, int c, vector<vector<int>>& matrix) {
        if (r < 0 || c < 0 || r>=matrix.size() || c>=matrix[0].size()) return false;
        return true;
    }
    
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        
        if (dp[r][c] != -1) return dp[r][c];
        
        int ans = 1, nr, nc;
        
        for (int d=0; d<4; ++d) {
            nr = r+dir[d], nc = c+dir[d+1];
            if (isValid(nr, nc, matrix) && matrix[nr][nc] > matrix[r][c]) 
                ans = max(ans, dfs(nr, nc, matrix, dp)+1);
        }
        
        return dp[r][c] = ans;
    }
};