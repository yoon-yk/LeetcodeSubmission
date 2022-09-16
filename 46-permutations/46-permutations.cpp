class Solution {
public:
    /*
            0
        1   2   3
       2 3 1 3 1 2
       3 2 3 1 2 1
    
    */
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        vector<vector<int>> ans;
        
        helper(nums, visited, path, ans);
        
        return ans;
    }
    
    
    // Swap 하는 방법
    // visited 하는 방법
    
    void helper(vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int>>& ans) {
        // condition
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            path.emplace_back(nums[i]);
            helper(nums, visited, path, ans);
            path.pop_back();
            visited[i] = false;
        }
        
        // 
    }
};