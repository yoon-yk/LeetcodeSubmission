class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        int n = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi-lo) >> 1);
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }  else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};