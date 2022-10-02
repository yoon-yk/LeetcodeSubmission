class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // backtracking - O(k^n)
            
        // memoization -- 
        // dynamic programming - ==> current order of dice, current sum 
        // tabulation 
        // memory optimization 
        
        int MOD = 1e9+7;
        vector<vector<int>> dp (n+1, vector<int>(target+1, 0));
        /*
        n = 2, k = 6, target = 7
        
        for dp[i][j], 
        if (i>0 && j - a >= 0) dp[i][j] += dp[i-1][j-a]; (( 1 <= a <= k ))
        else dp[i][j] = 0;
        
        n\target 0 1 2 3 4 5 6 7
        0        1 0 0 0 0 0 0 0
        1        1 1 1 1 1 1 1 0
        2        1 0 1 2 3 4 5 6
        
        */
        
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) 
            for (int j=1; j<=target; j++) 
                for (int x=1; x<=k; x++) 
                    if (j-x >= 0) 
                        dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;

        
        return dp[n][target];
    }
};