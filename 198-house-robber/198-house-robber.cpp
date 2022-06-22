class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        if (nums.size()==2) return max(nums[0], nums[1]);
        if (nums.size()==2) return max(nums[0]+nums[2], nums[1]);
        
        int *dp = new int[nums.size()];
        dp[0] = nums[0], dp[1] = nums[1], dp[2] = nums[0]+nums[2];
        
        for (int i=3; i<nums.size(); i++) {
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        
        int len = nums.size();
        return max(dp[len-1], dp[len-2]);
    }
};