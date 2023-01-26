class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1)); // hold, not hold 
        return maxProfits(0, false, prices, dp);
    }
    
    int maxProfits(int day, bool hold, vector<int>& prices, vector<vector<int>>& dp) {
        
        if (day >= prices.size()) return 0;

        if (dp[day][hold] != -1) return dp[day][hold];

        // sell 
        int sell = (hold) ? maxProfits(day+2, false, prices, dp) + prices[day] : INT_MIN;
        
        // buy
        int buy = (!hold) ? maxProfits(day+1, true, prices, dp) - prices[day] : INT_MIN;
        
        int skip = maxProfits(day+1, hold, prices, dp);
        
        return dp[day][hold] = max({sell, buy, skip});
    }
};