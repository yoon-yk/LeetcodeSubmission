class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mi = 0, hi = nums.size()-1;
        while (mi <= hi) {
            if (nums[mi] == 0) {
                swap(nums[lo], nums[mi]);
                ++lo, ++mi;
            } else if (nums[mi] == 2) {
                swap(nums[mi], nums[hi]);
                --hi;
            } else ++mi;
        }
    }
};