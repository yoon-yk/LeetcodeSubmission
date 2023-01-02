class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    if (i > 0 && j > 0) {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    } else dp[i][j] = 1;
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans*ans;
    }
};