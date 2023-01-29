class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> dict(days.begin(), days.end());
        vector<int> dp(366, -1);
        
        return backtrack(1, dict, costs, dp);
    }
    
    int backtrack(int day, unordered_set<int>& dict, vector<int>& costs, vector<int>& dp) {
        if (day > 365) return 0;
        if (dp[day] != -1) return dp[day];
        
        int oneDay, oneWeek, oneMonth, nextDay = INT_MAX;
        oneDay = backtrack(day+1, dict, costs, dp) + costs[0];
        oneWeek = backtrack(day+7, dict, costs, dp) + costs[1];
        oneMonth = backtrack(day+30, dict, costs, dp) + costs[2];
        
        if (!dict.count(day))
            nextDay = backtrack(day+1, dict, costs, dp);
        
        return dp[day] = min({oneDay, oneWeek, oneMonth, nextDay});
    }
};