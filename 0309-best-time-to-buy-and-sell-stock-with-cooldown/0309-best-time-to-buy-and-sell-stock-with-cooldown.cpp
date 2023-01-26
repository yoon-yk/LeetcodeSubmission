class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2)); // hold, not hold 
        dp[1][1] = -prices[0]; // buy on the first day
        dp[1][0] = 0; // not buy on the first day
        
        int sell, buy, hold;
        for (int i=2; i<=prices.size(); ++i) {
            // sell
            dp[i][false] = dp[i-1][true] + prices[i-1];
            
            // buy
            if (i>1) dp[i][true] = dp[i-2][false] - prices[i-1];
            
            // hold
            dp[i][false] = max(dp[i-1][false], dp[i][false]);
            dp[i][true] = max(dp[i-1][true], dp[i][true]);
        }
        
        
//         for (int i=0; i<=prices.size(); ++i) {
//             cout << dp[i][true] << " " << dp[i][false] << endl;
//         }
        
        return max(dp.back()[true], dp.back()[false]);
    }
};