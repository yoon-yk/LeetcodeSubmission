class Solution {
public:
    int f(int n, vector<int>& dp) {

        if (dp[n] != -1) return dp[n];

        int ans = n;
        for (int i=1; i<=(n+1)/2; ++i) {
            ans = max(ans, f(i, dp) * f(n-i, dp));
        }
        return dp[n] = ans; 
    }

    int integerBreak(int n) {
        if (n < 4) return n-1;
        vector<int> dp(60, -1);
        dp[0] = 0, dp[1] = 1;
        return f(n, dp);
    }
};