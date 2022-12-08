class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // you can't buy the day after you sell the stock
        // today choice = buy(if no cool day) / sell (if i had bought)
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return backtrack(0, false, prices, dp);
    }
    
    int backtrack(int idx, bool hold, vector<int>& prices, vector<vector<int>>& dp) {
        
        if (idx >= prices.size())
            return 0;
        
        if (dp[idx][hold] != -1)
            return dp[idx][hold];
        
        int ans = 0;
        if (hold) {
            // sell - and move to +2
            ans = backtrack(idx+2, !hold, prices, dp) + prices[idx];
            
            // not sell
            ans = max(ans, backtrack(idx+1, hold, prices, dp));
        } else {
            // buy 
            ans = backtrack(idx+1, true, prices, dp) - prices[idx];
            // or not buy
            ans = max(ans, backtrack(idx+1, false, prices, dp));
        }
        
        return dp[idx][hold] = ans;
    }
};