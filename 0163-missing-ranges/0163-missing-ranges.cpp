class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int prev = lower, cur = lower;
        vector<vector<int>> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (cur < nums[i]) {
                ans.push_back({prev, nums[i]-1});
                cur = nums[i];
            }
            prev = nums[i] + 1;
            ++cur;
        }
        if (nums.empty() || nums.back() < upper) {
            ans.push_back({prev, upper});
        }
        return ans;
    }
};