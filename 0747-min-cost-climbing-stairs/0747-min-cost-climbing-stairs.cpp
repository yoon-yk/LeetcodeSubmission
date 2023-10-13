class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        /*
        [10, 15, 20]
        [ 0,  0, 10, 15]
        */

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0, dp[1] = 0;        
        for (int i=2; i<=n; ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp.back();
    }
};