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
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans (2, -1);
        if (nums.empty()) return ans;
        int lb = findLowerBound(nums, target, 0, nums.size()-1);
        if (nums[lb] != target) return ans;
        else ans[0] = lb;
        int ub = findLowerBound(nums, target+1, lb, nums.size()-1);
        if (nums[ub] == target) ans[1] = ub;
        else ans[1] = ub-1;
        return ans;
    }
};