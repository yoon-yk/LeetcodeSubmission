class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return nums[0];
        vector<vector<int>> dp(n+1, vector<int>(2)); // include/exclude
        
        dp[0][0] = dp[0][1] = 0;
        dp[1][0] = nums[0];
        dp[1][1] = 0;
        
        for (int i=1; i<n; i++) {
            for (int k=0; k<2; k++) {
                dp[i+1][k] = max(dp[i-1][k] + nums[i], dp[i][k]);
            }
        }
        
        return max(dp[n-1][0], dp[n][1]);

    }
};