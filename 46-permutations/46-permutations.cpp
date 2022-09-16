class Solution {
public:
    /*
            0
        1   2   3
       2 3 1 3 1 2
       3 2 3 1 2 1
    */
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> path;
        vector<vector<int>> ans;
        
        helper(0, nums, path, ans);
        
        return ans;
    }
    
    
    // Swap 하는 방법
    // visited 하는 방법
    
    void helper(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        // condition
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            // path.emplace_back(nums[idx]);
            helper(idx+1, nums, path, ans);
            // path.pop_back();
            swap(nums[idx], nums[i]);
        }
        
        // 
    }
};