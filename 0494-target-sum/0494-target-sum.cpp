class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<unordered_map<int, int>> dp(n+1);
        
        
        /*
          -5 -4 -3 -2 -1  0  1  2  3
        0        0  0  0  1  0  0  0
        1        0  0  1  1  1  0  0
        2        0  1  1  3  1  1  0
        3        1  2  5  5  5  2  1 
        4        3  
  
        
        
        */
        dp[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            for (int s = -sum; s<=sum; ++s) {
                dp[i][s] += dp[i-1][s-nums[i-1]];
                dp[i][s] += dp[i-1][s+nums[i-1]];
            }
        }
        
        return dp[n][target];
    }
};