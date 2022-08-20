class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + (nums.size() >> 1), nums.end());
        return nums[nums.size() >> 1];
    }
};