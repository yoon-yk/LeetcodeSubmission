class Solution {
public:
    int findLowerBound(vector<int>& nums, int target, int lo, int hi) {
        int mi;
        // 1 2 3 4 5 
        while (lo < hi) {
            mi = lo + ((hi-lo) >> 1);
            if (nums[mi] < target)
                lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }
    
    int findUpperBound(vector<int>& nums, int target, int lo, int hi) {
        // 1 2 2 2 2 3 
        int mi;
        while (lo < hi) {
            mi = lo + ((hi-lo+1) >> 1);
            if (nums[mi] > target)
                hi = mi-1;
            else lo = mi;
        }
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans (2, -1);
        if (nums.empty()) return ans;
        int lb = findLowerBound(nums, target, 0, nums.size()-1);
        if (nums[lb] != target) return ans;
        else ans[0] = lb;
        int ub = findUpperBound(nums, target, lb, nums.size()-1);
        ans[1] = ub;
        return ans;
    }
};