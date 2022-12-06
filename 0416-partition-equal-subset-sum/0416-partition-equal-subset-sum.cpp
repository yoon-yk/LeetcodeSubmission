class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum >> 1;
        if (*max_element(nums.begin(), nums.end()) > target) return false;
        
        int n = nums.size();
        vector<bool> dp(target+1, false);
        
        dp[0] = true;
        for (int i=0; i<n; ++i) {
            for (int s=target; s>=nums[i]; --s) {
                if (dp[s-nums[i]]) dp[s] = true;
            }
        }
                
        return dp[target];
    }
};