class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur = nums;
        vector<vector<int>> ans;
        
        backtrack(0, nums, ans);
        
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& ans) {
                
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        else {
            for (int j=idx; j < nums.size(); j++) {
                swap(nums[idx], nums[j]);
                backtrack(idx+1, nums, ans);
                swap(nums[idx], nums[j]);
            }
        }

    }
};