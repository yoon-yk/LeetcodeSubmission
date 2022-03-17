class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;
        for (int i=0; i<nums.size(); i++){
            // 지금 index로 끝나는 sub-array 중에 가장 큰 것 
            curSum = max(nums[i], curSum+nums[i]); 
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};