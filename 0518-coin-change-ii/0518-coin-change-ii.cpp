class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1));
        dp[0][0] = 1;
        for (int c=1; c<=coins.size(); ++c) {
            for (int a=0; a<=amount; ++a) {
                auto & coin = coins[c-1];
                dp[c][a] = dp[c-1][a];
                if (a-coin >= 0) {
                    dp[c][a] += dp[c][a-coin];
                } 
            }
        }
    
        return dp[coins.size()][amount];
    }
};