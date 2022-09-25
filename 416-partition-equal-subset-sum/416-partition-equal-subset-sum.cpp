class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) sum+= nums[i];
        if (sum % 2) return false;
        
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
        dp[0][0] = true;
        
        
        for (int i=1; i<=nums.size(); i++) {
            for (int j=0; j<=sum; j++) {
                if (dp[i-1][j]) {
                    dp[i][j] = true;
                    if (j+nums[i-1] <= sum) 
                        dp[i][j+nums[i-1]] = true;
                }
            }
        }
        
        // for (int i=0; i< nums.size(); )
        // return true;
        return dp[nums.size()][sum >> 1];
    }
};