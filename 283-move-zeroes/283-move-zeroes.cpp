class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = 0, ptr = 0;
        while (ptr < nums.size()) {
            if (nums[zeroIdx] != 0) { // Increase zeroIdx until encountering zero cell 
                ptr = ++zeroIdx;
            }
            else { // If zeroIdx points to zero
                if (nums[ptr] == 0) { // Adjust ptr to the non-zero cell
                    ptr++;
                }
                else { // Swap elems if ptr points to non-zero and zeroIdx points to zero
                    swap(nums[zeroIdx], nums[ptr]);
                    ++zeroIdx; ++ptr;
                }
            }
        }
    }
};