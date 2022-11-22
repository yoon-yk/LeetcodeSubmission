class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size(), minL = INT_MAX, left = 0, sum = 0;
        for (int right=0; right<n; right++) {
            sum += nums[right];
            
            while (sum >= target) {
                minL = min(right-left+1, minL);
                sum -= nums[left];
                left ++;
            }
        }
        return (minL < INT_MAX) ? minL : 0;
    }
};