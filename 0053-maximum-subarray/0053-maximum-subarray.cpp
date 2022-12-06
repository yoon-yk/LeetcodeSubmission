class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Prefix sum?
        
        //    -2  1 -3  4 -1  2  1 -5  4
        //  0 -2 -1 -4  0 -1  1  2 -3  1 - prefix
        //  0 -2 -1 -1  4                - minimum Sum
        // current - minimum 
        
        int n = nums.size(), preSum = 0;
        int ans = nums[0], minN = 0;
        for (int i=0; i<n; ++i) {
            preSum += nums[i];
            ans = max(ans, preSum - minN);
            minN = min(preSum, minN);
        }
        
        return ans;
    }
};