class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIdx = 0, zeroIdx = 0;
        for (; zeroIdx<nums.size(); zeroIdx++){
            if (nums[zeroIdx]!=0)
                swap(nums[zeroIdx],nums[nonZeroIdx++]);
        }
    }
};