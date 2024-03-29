class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<uint> dp(target+1, 0);
        dp[0] = 1;
        
        for (int i=0; i<=target; i++) {
            for (int j=0; j<nums.size(); j++){
                if (i-nums[j] < 0) break;
                dp[i] += dp[i-nums[j]];
            }
        }
        
        return dp[target];
    }
};