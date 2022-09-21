class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int curSum = 0;
        vector<int> curPath;
        vector<vector<int>> ans;
        
        backtrack(0, candidates, target, curSum, curPath, ans);
        return ans;
        
    }
    
    void backtrack(int idx, vector<int>& candidates, int target, int &curSum, vector<int>& curPath, vector<vector<int>>& ans) {
        // base case
        if (curSum == target){ 
            ans.emplace_back(curPath);
            return;
        }

        for (int i=idx; i<candidates.size(); i++) {
            if (i > idx && (candidates[i-1] == candidates[i])) continue;
            if (curSum + candidates[i] > target) continue;
            curPath.emplace_back(candidates[i]);
            curSum += candidates[i];
            backtrack(i+1, candidates, target, curSum, curPath, ans);
            curSum -= candidates[i];
            curPath.pop_back();
        }
    }
};