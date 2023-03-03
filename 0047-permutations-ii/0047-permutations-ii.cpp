class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, ans);
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        set<int> seen;
        
        for (int i=idx; i<nums.size(); ++i) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[i], nums[idx]);
            backtrack(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
    
};
