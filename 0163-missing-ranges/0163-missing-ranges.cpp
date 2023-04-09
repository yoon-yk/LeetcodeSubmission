class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int prev = lower, cur = lower;
        vector<vector<int>> ans;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == cur) {
                prev = nums[i] + 1;
                cur += 1;
            } else if (cur < nums[i]) {
                ans.push_back({prev, nums[i]-1});
                prev = nums[i] + 1;
                cur = nums[i] + 1;
            }
        }
        if (nums.empty() || nums.back() < upper) {
            ans.push_back({prev, upper});
        }
        return ans;
    }
};