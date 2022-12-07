class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            for (int k=0; k<=amount; ++k) {
                if (k-coins[i] >= 0 )
                    dp[k] = min(dp[k], dp[k-coins[i]] + 1);
            }
        }
        
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};