class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        
        for (int& n : nums) {
            vector<vector<int>> newSubsets;
            for (vector<int> curr : ans) {
                curr.push_back(n);
                newSubsets.push_back(curr);
            }
            for (vector<int>& curr : newSubsets)
                ans.push_back(curr);
        }
        
        return ans;
    }

};