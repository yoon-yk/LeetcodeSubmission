class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int curSum = nums[left] + nums[right];
            if (curSum == target) return {left+1, right+1};
            if (target < curSum)
                right--;
            else left ++;
        }
        return {};
    }
};