class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(begin(days), end(days));
        vector<int> dp(366);
        dp[0] = 0;
        for (int d=1; d<366; ++d) {
            if (!travel.count(d)) dp[d] = dp[d-1];
            else dp[d] = min({dp[d-1]+costs[0], dp[max(0, d-7)]+costs[1],
                              dp[max(0, d-30)] + costs[2]});
        }
        return dp[365];
    }
};