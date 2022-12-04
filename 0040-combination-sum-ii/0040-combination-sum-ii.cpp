class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int>cur;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, cur, ans);
        return ans;
        
    }
    
    void backtrack(int idx, int target, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        if (target < 0 || idx == nums.size())
            return;
        
        for (int i=idx; i<nums.size(); i++) {
            if (i>idx && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(i+1, target-nums[i], nums, cur, ans);
            cur.pop_back();
        }
        
    }
    
};