class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int c=1; c<=coins.size(); ++c) {
            for (int a=0; a<=amount; ++a) {
                auto & coin = coins[c-1];
                if (a-coin >= 0) {
                    dp[a] = min(dp[a], dp[a-coin] + 1);
                } 
            }
        }
    
        return dp[amount] > amount ? -1 : dp[amount];
    }
};