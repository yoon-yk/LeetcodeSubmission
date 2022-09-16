class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
       
        vector<vector<int>> dp (mul.size()+1, vector<int>(mul.size()+1, INT_MAX));
        return helper(nums, mul, dp, 0, 0);
    }

    int helper(vector<int>& nums, vector<int>& mul, vector<vector<int>>& dp, int idx, int lo) {

        if (idx == mul.size())
            return 0;
        
        if (dp[idx][lo] != INT_MAX) 
            return dp[idx][lo];

        // lo++
        int l = (mul[idx] * nums[lo]) + helper(nums, mul, dp, idx+1, lo+1);
        
        // hi--
        int hi = (nums.size() - 1) - (idx - lo);
        int r = (mul[idx] * nums[hi]) + helper(nums, mul, dp, idx+1, lo);
        
        return dp[idx][lo] = max(l, r);
        
    }
};