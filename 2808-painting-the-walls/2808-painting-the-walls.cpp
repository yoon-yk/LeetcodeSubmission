class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& t) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // idx, timeLefting t
        return solve(0, n, cost, t, dp);
    }
    
    int solve(int i, int timeLeft, vector<int>& cost, vector<int>& t, vector<vector<int>>& dp) { 
        if (timeLeft <= 0) {
            return 0;
        }
        
        if (i == cost.size()) {
            return 1e9;
        }
        
        if (dp[i][timeLeft] != -1) {
            return dp[i][timeLeft];
        }
        
        int paint = cost[i] + solve(i + 1, timeLeft - 1 - t[i], cost, t, dp);
        int dontPaint = solve(i + 1, timeLeft, cost, t, dp);
    
        return dp[i][timeLeft] = min(paint, dontPaint);
    }
};
