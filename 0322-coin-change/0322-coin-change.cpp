class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, amount+1));
        dp[0][0] = 0;
        for (int c=1; c<=coins.size(); ++c) {
            for (int a=0; a<=amount; ++a) {
                dp[c][a] = dp[c-1][a];
                auto & coin = coins[c-1];
                if (a-coin >= 0) {
                    dp[c][a] = min(dp[c][a], dp[c][a-coin] + 1);
                } 
            }
        }
    
        return dp[coins.size()][amount] > amount ? -1 : dp[coins.size()][amount];
    }
};