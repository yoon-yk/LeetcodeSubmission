class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int curSum = 0;
        vector<int> curPath;
        vector<vector<int>> ans;
        
        backtrack(1, k, n, curSum, curPath, ans);

        return ans;
    }
    
    void backtrack(int idx, int k, int n, int &curSum, vector<int>& curPath, vector<vector<int>>& ans) {
        // base case
        
        if (curSum == n && curPath.size() == k) {
            ans.push_back(curPath);
            return;
        }
        
        if (curSum > n || curPath.size() > k) {
            return;
        }
        
        // dfs
        for (int i=idx; i<10; i++){
            curPath.push_back(i);
            curSum += i;
            backtrack(i+1, k, n, curSum, curPath, ans);
            curSum -= i;
            curPath.pop_back();
        }
    }
};