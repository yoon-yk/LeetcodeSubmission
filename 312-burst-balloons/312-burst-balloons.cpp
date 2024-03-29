class Solution {
public:

    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return bruteForce(nums, 1, n-2, dp);
    }
    
    int bruteForce(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
                
        if (dp[l][r] != -1)
            return dp[l][r];
            
        int maxSum = 0;
        int remainingLeft, remainingRight, gain;
        for (int i=l; i<=r; i++) {
            gain = nums[l - 1] * nums[i] * nums[r + 1];
            remainingLeft = (i-1 >= l) ? bruteForce(nums, l, i-1, dp) : 0;
            remainingRight = (i+1 <= r) ? bruteForce(nums, i+1, r, dp) : 0; 
            maxSum = max(remainingLeft+remainingRight+gain, maxSum);
        }
        
        return dp[l][r] = maxSum;
    }
};