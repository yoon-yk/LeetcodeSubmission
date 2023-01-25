class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mi;
        while (lo <= hi) {
            mi = lo + ((hi-lo)>>1);
            if (mi > 0 && nums[mi-1] > nums[mi])
                return nums[mi];
            if (nums[mi] > nums[hi]) {
                lo = mi+1;
            } else {
                hi = mi-1;
            }        
        }
        return nums[lo];
    }
};