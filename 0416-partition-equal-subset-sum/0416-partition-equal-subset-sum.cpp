class Solution {
public:
    int mod = 1e9 + 7;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum >> 1;
        
        return subarraySumEqualKExist(nums, target);
    }
    
    bool subarraySumEqualKExist(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1, 
                               vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<=nums.size(); ++i) {
            if (nums[i-1] > target) continue;
            for (int s=0; s<=target; ++s) {
                dp[i][s] = dp[i-1][s];
                if (s-nums[i-1] >= 0) {
                    dp[i][s] = (dp[i-1][s-nums[i-1]] + dp[i][s]) % mod;
                }
            }
        }
        
        
        return dp[nums.size()][target];
    }
};