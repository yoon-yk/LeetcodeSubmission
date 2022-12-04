class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        sort(nums.begin(), nums.end());
        backtrack(0, nums, cur, ans);
        
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        
        ans.push_back(cur);

        if (idx == nums.size()) 
            return;
        
        for (int i=idx; i<nums.size(); i++) {
            if (i>idx && nums[i-1] == nums[i]) 
                continue;
            cur.push_back(nums[i]);
            backtrack(i+1, nums, cur, ans);
            cur.pop_back();
        }
    }
};