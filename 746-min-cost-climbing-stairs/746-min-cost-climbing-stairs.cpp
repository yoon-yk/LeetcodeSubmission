class Solution {
public:
    int* dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        dp = new int[len];
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i=2; i<len; i++) {
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        }

        
        return min(dp[len-2], dp[len-1]);
    }
};