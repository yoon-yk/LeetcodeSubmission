class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        backtrack(0, nums, cur, ans);
        
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        
        if (idx == nums.size()) {
            ans.push_back(cur);
            return;
        }
            
        // exclude current idx
        backtrack(idx+1, nums, cur, ans);

        // include current idx
        cur.push_back(nums[idx]);
        backtrack(idx+1, nums, cur, ans);
        cur.pop_back();
    }
};