class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, 
                               vector<int>(amount+1, amount+1));
        dp[0][0] = 0;
        for (int i=1; i<=coins.size(); ++i) {
            for (int j=0; j<=amount; ++j) {
                int & c = coins[i-1];
                dp[i][j] = dp[i-1][j];
                if (j-c >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j-c] + 1);
            }
        }
        
        // for (int i=1; i<=coins.size(); ++i) {
        //     for (int j=0; j<=amount; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = dp[coins.size()][amount];
        return ans > amount ? -1 : ans;
    }
};