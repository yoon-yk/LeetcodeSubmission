class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<vector<int>> dp(r, vector<int>(c, -1));
        
        int ans = 0;
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                visited[i][j] = true;
                ans = max(ans, dfs(i, j, matrix, visited, dp));
                visited[i][j] = false;
            }
        }
        
        return ans;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    bool validRange(int i, int j, vector<vector<int>>& matrix, int curMax) {
        if (i< 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= curMax)
            return false;
        return true;
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& dp) {
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 1;
        int curVal = matrix[i][j];
        int nI, nJ;
        
        for (int d=0; d<4; ++d) {
            nI = i+dir[d], nJ = j+dir[d+1];
            if (!validRange(nI, nJ, matrix, curVal) || visited[nI][nJ]) continue;
            visited[nI][nJ] = true;
            ans = max(ans, dfs(nI, nJ, matrix, visited, dp)+1);
            visited[nI][nJ] = false;
        }
        
        return dp[i][j] = ans;
    }
};