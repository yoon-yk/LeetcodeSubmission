class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        auto hi = upper_bound(nums.begin(), nums.end(), target);
        int lb = (lo == nums.end() || *lo != target)? -1 : lo-nums.begin();
        int ub = (lb == -1 || hi == nums.begin())? -1 : prev(hi)-nums.begin();
        
        return {lb, ub};
    }
};