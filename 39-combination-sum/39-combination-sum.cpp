class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> cur;
        vector<vector<int>> ans;
        
        backtrack(candidates, 0, target, cur, ans);
        
        return ans;
    }
    
    void backtrack(vector<int>& candidates, int idx, int curSum, vector<int>& cur, vector<vector<int>>& ans) {
        
        if (idx > candidates.size() || curSum < 0)
            return;
        
        if (curSum == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i=idx; i<candidates.size(); i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, i, curSum-candidates[i], cur, ans);
            cur.pop_back();
        }
        
    }
    
};