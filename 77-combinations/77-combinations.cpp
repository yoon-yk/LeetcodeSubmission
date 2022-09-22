class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curPath;
        vector<vector<int>> ans;
        
        backtrack(1, n, k, curPath, ans);
        
        return ans;
    }
    
    void backtrack(int idx, int n, int k, vector<int>& curPath, vector<vector<int>>& ans) {
        if (curPath.size() == k) {
            ans.push_back(curPath);
        } else if (curPath.size() > k) {
            return;
        }
        else {
            for (int i=idx; i<=n; i++) {
                curPath.push_back(i);
                backtrack(i+1, n, k, curPath, ans);
                curPath.pop_back();
            }
        }

    }
};