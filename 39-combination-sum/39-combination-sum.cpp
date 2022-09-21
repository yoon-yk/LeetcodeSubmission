class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int curSum = 0;
        vector<int> curPath;
        vector<vector<int>> ans;
        backtrack(0, candidates, target, curPath, curSum, ans);
        return ans;
    }
    
    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& curPath, int &curSum, vector<vector<int>>& ans) {
        int n = candidates.size();
        
        if (curSum == target) {
            ans.push_back(curPath);
            return;
        }
        
        
        for (int i=idx; i<n; i++) {
            if (candidates[i] + curSum > target) continue;
            curSum += candidates[i];
            curPath.push_back(candidates[i]);
            backtrack(i, candidates, target, curPath, curSum, ans);
            curPath.pop_back();
            curSum -= candidates[i];
        }
    }
};