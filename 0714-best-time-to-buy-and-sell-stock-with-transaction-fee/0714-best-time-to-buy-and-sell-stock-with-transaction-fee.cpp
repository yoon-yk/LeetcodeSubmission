class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell, buy;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i=1; i<prices.size(); ++i) {
            sell = dp[i-1][true] - fee + prices[i];
            buy = dp[i-1][false] - prices[i];
            dp[i][true] = max(dp[i-1][true], buy);
            dp[i][false] = max(dp[i-1][false], sell);
        }

        return max(dp.back()[true], dp.back()[false]);
    }
};