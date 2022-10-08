class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        for (int i=0; i<n; i++)
            sum += nums[i];
        
        if (target < -1 * sum || target > sum) return 0;

        /***
          -5 -4 -3 -2 -1 0 1 2 3 4 5
           0  1  2  3  4 5 6 7 8 9 10
        0              1   1
        1           1    2   1
        2
        3
        4
        5
        
        
        ***/
        vector<vector<int>> dp(n+1, vector<int> ((sum<<1)+1, 0));
    
        dp[0][sum] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=-sum; j<=sum; j++) {
                if (j+sum - nums[i-1] >= 0)
                    dp[i][(j+sum)] += dp[i-1][(j+sum)-nums[i-1]]; // minus
                if (j+sum + nums[i-1] <= (sum << 1))
                    dp[i][(j+sum)] += dp[i-1][(j+sum)+nums[i-1]]; // plus

            }
        }
        return dp[n][sum+target];
    }
    
};