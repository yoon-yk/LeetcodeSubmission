class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0, prev = -1000;
        for (int i=0; i<nums.size(); ++i) {
            if (prev < nums[i]) {
                prev = nums[i];
                swap(nums[unique++], nums[i]);
            }
        }
        return unique;
    }
};