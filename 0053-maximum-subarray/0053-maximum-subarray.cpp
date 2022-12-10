class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        prefix sum
        [-2, 1,-3, 4,-1, 2, 1,-5, 4]
        [-2,-1,-4, 0,-1, 1, 2,-3, 1]
        
        [ 5, 4,-1, 7, 8]
        [ 5, 9, 8,15,23]
        maximum Sum - minimum Sum 
        */
        
        int n = nums.size();
        int curSum = nums[0], maxSum = nums[0];
        for(int i=1; i<n; ++i) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};