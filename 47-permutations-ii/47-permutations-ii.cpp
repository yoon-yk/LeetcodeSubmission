class Solution {
public:
    
    /*
         [1, 1, 2]

            x x   x
        1 1 1 1 2 2
        1 2 1 2 1 1
        2 1 2 1 1 1
    
    */
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        
        helper(0, nums, ans);
        
        return ans;
    }
    
    void helper (int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            
            ans.emplace_back(nums);
            return;
        }
        
        unordered_set<int> seen;
        for (int i=idx; i<nums.size(); i++) {  
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[i], nums[idx]);
            // path.emplace_back(nums[idx]);
            helper(idx+1, nums, ans);
            // path.pop_back();
            swap(nums[i], nums[idx]);
        }
    }
};