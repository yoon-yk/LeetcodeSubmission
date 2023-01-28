class Solution {
public:
    int numSquares(int n) {
        int maxN = sqrt(n);
        vector<vector<int>> dp(maxN+1, vector<int>(n+1, n+1));
        dp[0][0] = 0;
        for (int i=1; i<=maxN; ++i) {
            for (int s=0; s<=n; ++s) {
                dp[i][s] = dp[i-1][s];
                if (s-(i*i) >= 0) {
                    dp[i][s] = min(dp[i][s], dp[i][s-(i*i)] + 1);
                }
            }
        }
        return dp[maxN][n];
    }
};