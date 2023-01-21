class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nzeros = 0, zeros = nums.size();
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nzeros]);
                ++nzeros;
            }
        }
    }
};