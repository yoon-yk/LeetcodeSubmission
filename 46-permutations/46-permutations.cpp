class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        
        backtrack(0, nums, ans, cur);
        
        return ans;
    }
    
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur) {
                
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        else {
            for (int i=0; i < nums.size(); i++) {
                if (find(cur.begin(), cur.end(), nums[i])!=cur.end()) continue; // element already exists, skip
                cur.push_back(nums[i]);
                backtrack(i+1, nums, ans, cur);
                cur.pop_back();
            }
        }

    }
};