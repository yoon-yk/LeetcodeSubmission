class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), -1));
        return backtrack(false, 0, prices, fee, dp);
    }
    
    int backtrack(bool hold, int day, vector<int>& prices, int fee, 
                  vector<vector<int>>& dp) {
        if (day == prices.size()) return 0;
        if (dp[hold][day] != -1) return dp[hold][day];
        
        int keep = backtrack(hold, day+1, prices, fee, dp), option;
        if (hold) {
            option = backtrack(!hold, day+1, prices, fee, dp) - fee + prices[day];
        } else {
            option = backtrack(!hold, day+1, prices, fee, dp) - prices[day];
        }
        return dp[hold][day] = max(keep, option);
    }
};