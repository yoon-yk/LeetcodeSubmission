class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // lower bound
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        if (lo == nums.end() || *lo != target) return {-1, -1};
        
        // upper bound
        auto hi = upper_bound(lo, nums.end(), target); // greater 
        return {(int)(lo-nums.begin()), (int)(prev(hi) - nums.begin())};
    }
};