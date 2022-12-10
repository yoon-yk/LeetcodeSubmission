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
        int prefixSum = 0, minSum = 0;
        int ans = nums[0];
        for(int i=0; i<n; ++i) {
            prefixSum += nums[i];
            ans = max(ans, prefixSum-minSum);
            minSum = min(minSum, prefixSum);
        }
        
        return ans;
    }
};