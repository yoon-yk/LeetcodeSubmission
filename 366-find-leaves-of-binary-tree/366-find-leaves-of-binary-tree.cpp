class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
    
        vector<vector<int>> ans(100);
        
        int maxDep = -1;
        dfs(root, ans, maxDep);
        ans.resize(maxDep+1);
        
        return ans;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& ans, int& maxDep) {
        
        int dep, left = 0, right = 0; 
        if (root->left)
            left = dfs(root->left, ans, maxDep)+1;
        if (root->right)
            right = dfs(root->right, ans, maxDep)+1;
        
        dep = max(left, right);
        maxDep = max(maxDep, dep);
        ans[dep].push_back(root->val);
        return dep;
    }    
};