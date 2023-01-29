class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int kDays = 365;
        unordered_set<int> travelDays(days.begin(), days.end());
        vector<int> dp(kDays+1);
        dp[0] = 0;
        for (int i = days.front(); i<=days.back(); ++i) {
            if (!travelDays.count(i)) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({
                    dp[i-1] + costs[0],
                    dp[max(0, i-7)] + costs[1],
                    dp[max(0, i-30)] + costs[2]
                });   
            }
        }
        return dp[days.back()];
    }
};