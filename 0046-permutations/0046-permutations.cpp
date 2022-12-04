class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size())
            ans.push_back(nums);
        
        for (int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            backtrack(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
};