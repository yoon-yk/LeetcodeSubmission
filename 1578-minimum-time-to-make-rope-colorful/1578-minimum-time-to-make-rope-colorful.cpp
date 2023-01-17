class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), ans = 0;
        vector<int> dp(n, 0);
        int sum = neededTime[0];
        dp[0] = neededTime[0];
        
        /*
        a a a a b b b
        1 2 3 4 2 3 4
        1 2 3 4 2 3 4
        
        */
        for (int i=1; i<=n; ++i) {
            if (i > 0 && colors[i] == colors[i-1]) {
                dp[i] = max(dp[i-1], neededTime[i]);
                sum += neededTime[i];
            } else {
                if (i > 0) ans += (sum - dp[i-1]);
                if (i == n) break;
                dp[i] = neededTime[i];
                sum = neededTime[i];
            }
        }
        
        
        return ans;
    }
};