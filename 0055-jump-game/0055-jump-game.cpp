class Solution {
public:
    
    /*
        <0 1 2 3 4>
        [2,3,1,1,4]
        [2,4,3,4,8]
        
        <0 1 2 3 4>
        [3,2,1,0,4]
        [3,3,3,3,8]
   
        <0 1 2 3 4>
        [3,1,1,1,4]
        [3,1,3,4,8]
        
        <0 1 2 3 4>
        [0,0,2,0,4]
        [0,1,3,3,8]
        
        */
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return backtrack(0, nums, dp);
    }
    bool backtrack(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size()-1)
            return true;
        
        if (dp[idx]!= -1) return dp[idx];
        
        for (int i=1; i<=nums[idx]; i++) {
            if (backtrack(idx+i, nums, dp)) 
                return nums[idx] = true;
        }
        
        return nums[idx] = false;
    }
};