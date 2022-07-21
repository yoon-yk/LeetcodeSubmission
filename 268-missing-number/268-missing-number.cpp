class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = nums.size()*(nums.size() + 1)/2;
        for (auto number : nums)
            total -= number;
        return total;
    }
};