class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        int include1 = backtrack(2, nums, true, dp) + nums[0];
        int exclude1 = backtrack(1, nums, false, dp);
        return max(include1, exclude1);
    }
    
    int backtrack(int idx, vector<int>& nums, bool fIncluded, vector<vector<int>>& dp) {
        
        if (idx >= nums.size())
            return 0;
        if (dp[idx][fIncluded] != -1)
            return dp[idx][fIncluded];
        
        int ans = backtrack(idx + 1, nums, fIncluded, dp); // skip
        if (!fIncluded || idx != nums.size()-1) 
        ans = max(ans, backtrack(idx + 2, nums, fIncluded, dp) + nums[idx]); // include
        return dp[idx][fIncluded] = ans;
        
    }
    
};