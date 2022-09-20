class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curPath;
        vector<vector<int>> ans;
        backtrack(0, nums, curPath, ans);
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<int>& curPath, vector<vector<int>>& ans) {
        
        ans.push_back(curPath);

        int n = nums.size();

        if (idx == n) {
            return;
        }
        
        
        for (int i=idx; i<n; i++) {
            curPath.push_back(nums[i]);
            backtrack(i+1, nums, curPath, ans);
            curPath.pop_back();
        }
    }
};