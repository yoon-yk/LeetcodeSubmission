class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i<=coins.size(); ++i) {
            for (int j=0; j<=amount; ++j) {
                int & c = coins[i-1];
                if (j-c >= 0)
                    dp[j] = min(dp[j], dp[j-c] + 1);
            }
        }
        
        // for (int i=1; i<=coins.size(); ++i) {
        //     for (int j=0; j<=amount; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = dp[amount];
        return ans > amount ? -1 : ans;
    }
};