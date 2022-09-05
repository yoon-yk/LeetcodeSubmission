class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
    
        vector<vector<int>> ans;
        dfs(root, ans);
        
        return ans;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& ans) {
        
        int height, left = 0, right = 0; 

        if (root->left)
            left = dfs(root->left, ans)+1;
        if (root->right)
            right = dfs(root->right, ans)+1;
        height = max(left, right);


        if ((int) ans.size() < height+1) 
            ans.push_back(vector<int>());
        ans[height].push_back(root->val);
        
        return height;
    }    
};