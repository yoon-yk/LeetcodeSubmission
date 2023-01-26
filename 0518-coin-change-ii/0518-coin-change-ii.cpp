class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int c=1; c<=coins.size(); ++c) {
            for (int a=0; a<=amount; ++a) {
                auto & coin = coins[c-1];
                if (a-coin >= 0) {
                    dp[a] += dp[a-coin];
                } 
            }
        }
    
        return dp[amount];
    }
};