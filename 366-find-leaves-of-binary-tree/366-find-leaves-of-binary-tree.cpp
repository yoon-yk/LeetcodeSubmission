class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
    
        vector<vector<int>> ans;
        
        int maxHeight = -1;
        dfs(root, ans, maxHeight);
        
        return ans;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& ans, int& maxHeight) {
        
        int height, left = 0, right = 0; 
        if (!root->left && !root->right) {
            height = 0;
        } else {
            if (root->left)
                left = dfs(root->left, ans, maxHeight)+1;
            if (root->right)
                right = dfs(root->right, ans, maxHeight)+1;
            height = max(left, right);
        }

        maxHeight = max(maxHeight, height);
        if ((int) ans.size() < height+1) ans.push_back(vector<int>());
        ans[height].push_back(root->val);
        return height;
    }    
};