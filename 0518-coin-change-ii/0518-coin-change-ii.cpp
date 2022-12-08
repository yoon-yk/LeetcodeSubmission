class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            for (int s=0; s<=amount; ++s) {
                if (s-coins[i] >= 0) {
                    dp[s] += dp[s-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};