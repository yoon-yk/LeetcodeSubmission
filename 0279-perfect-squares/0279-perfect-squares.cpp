class Solution {
public:
    int numSquares(int n) {
        int maxN = sqrt(n);
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i=1; i<=maxN; ++i) {
            for (int s=0; s<=n; ++s) {
                if (s-(i*i) >= 0) {
                    dp[s] = min(dp[s], dp[s-(i*i)] + 1);
                }
            }
        }
        return dp[n];
    }
};