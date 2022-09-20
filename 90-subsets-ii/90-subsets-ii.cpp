class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
        
        vector<bool> visited(20, false);
        
        for (int i=idx; i<n; i++) {
            if (visited[nums[i]+10]) continue;
            visited[nums[i]+10] = true;
            curPath.push_back(nums[i]);
            backtrack(i+1, nums, curPath, ans);
            curPath.pop_back();
        }
        
    }
};