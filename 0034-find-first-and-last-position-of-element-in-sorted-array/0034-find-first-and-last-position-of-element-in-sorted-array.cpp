class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int lo = 0, hi = nums.size()-1, mid;
        while (lo < hi) {
            mid = lo + ((hi-lo) >> 1);
            if (nums[mid] < target) lo = mid+1;
            else hi = mid;
        }
        if (nums[lo] != target) return {-1, -1};
        
        vector<int> ans = {lo, -1};
        hi = nums.size()-1;
        while (lo < hi) {
            mid = lo + ((hi-lo+1) >> 1);
            if (target < nums[mid]) hi = mid-1;
            else lo = mid;
        }
        ans[1] = lo;
        
        return ans;
    }
};