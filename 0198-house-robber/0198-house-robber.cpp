class Solution {
public:
    int rob(vector<int>& nums) {
        
        /*
        base case
        dp[0] = 0, dp[1] = nums[0];
        
        recurrence relation
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        지금 여기서 훔치거나, 넘기거나
        */
        
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = 0, dp[1] = nums[0];
        for (int i=2; i<=n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp.back();
    }
};