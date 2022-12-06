class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return backtrack(0, nums, dp);
    }
    
    int backtrack(int idx, vector<int>& nums, vector<int>& dp) {
        
        if (idx >= nums.size())
            return 0;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        // take the current and start from the next next one
        int ch1 = backtrack(idx+2, nums, dp) + nums[idx];
        
        // skip this and start from the next one
        int ch2 = backtrack(idx+1, nums, dp);
        
        return dp[idx] = max(ch1, ch2);
    }
};