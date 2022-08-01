class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = 0, ptr = 0;
        while (ptr < nums.size()) {
            if (nums[zeroIdx]) {
                ++zeroIdx;
                ptr = zeroIdx;
            }
            else {
                if (!nums[ptr]) {
                    ptr++;
                }
                else {
                    swap(nums[zeroIdx], nums[ptr]);
                }
            }
        }
    }
};