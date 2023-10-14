class Solution {
public:
    // The longer the paid painter paints, 
    // the more we can make use of the free painter. 

    int paintWalls(vector<int>& cost, vector<int>& t) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // idx, remainingWalls
        return solve(0, n, cost, t, dp);
    }
    
    int solve(int i, int remainingWalls, vector<int>& cost, vector<int>& t, vector<vector<int>>& dp) { 
        
        // painted all 
        if (remainingWalls <= 0) {
            return 0;
        }
        
        // no painters left
        if (i == cost.size()) {
            return 1e9;
        }
        
        if (dp[i][remainingWalls] != -1) {
            return dp[i][remainingWalls];
        }
        
        // t[i] + 1 == # of walls (free painter paints + cur painter paints)
        int paint = cost[i] + solve(i + 1, remainingWalls - 1 - t[i], cost, t, dp); 

        // skip; let a free painter paint it 
        int dontPaint = solve(i + 1, remainingWalls, cost, t, dp);
    
        return dp[i][remainingWalls] = min(paint, dontPaint);
    }
};
