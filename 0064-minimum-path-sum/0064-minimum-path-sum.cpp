class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int left, top;
        int rsz = grid.size(), csz = grid[0].size();
        vector<vector<int>> dp(rsz, vector<int>(csz, 0));
        for (int i=0; i<rsz; ++i) {
            for (int j=0; j<csz; ++j) {
                // from left or top
                if (i==0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                left = j > 0 ? dp[i][j-1] : INT_MAX;
                top = i > 0 ? dp[i-1][j] : INT_MAX;
                dp[i][j] = min(left, top) + grid[i][j];
            }
        }
        return dp[rsz-1][csz-1];
    }
};