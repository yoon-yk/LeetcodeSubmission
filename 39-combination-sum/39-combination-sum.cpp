class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> cur;
        vector<vector<int>> ans;
        
        backtrack(candidates, 0, target, cur, ans);
        
        return ans;
    }
    
    void backtrack(vector<int>& candidates, int idx, int curSum, vector<int>& cur, vector<vector<int>>& ans) {
        
        if (idx == candidates.size() || curSum < 0)
            return;
        else if (curSum == 0) {
            ans.push_back(cur);
            return;
        }
        else {
            backtrack(candidates, idx+1, curSum, cur, ans); // exculde
            cur.push_back(candidates[idx]);
            backtrack(candidates, idx, curSum-candidates[idx], cur, ans); // include 
            cur.pop_back();
        }
    }
    
};