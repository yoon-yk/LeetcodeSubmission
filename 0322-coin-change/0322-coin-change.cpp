class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, amount+1));
        dp[0][0] = 0;
        for (int i=1; i<=n; ++i) {
            for (int k=0; k<=amount; ++k) {
                dp[i][k] = dp[i-1][k];
                if (k-coins[i-1] >= 0 )
                    dp[i][k] = min(dp[i][k], dp[i][k-coins[i-1]] + 1);
            }
        }
        
        return (dp[n][amount] > amount) ? -1 : dp[n][amount];
    }
};