class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        sort(nums.begin(), nums.end());
        return helper(nums, dp, target);
    }
    
    int helper(vector<int>& nums, vector<int>& dp, int target) {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if (target-nums[i] < 0) break;
            ans += helper(nums, dp, target-nums[i]);
        }
        return dp[target] = ans;
        
    }
};