class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
    
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> m;
        
        dfs(root, m);
        
        for (int i=0; i<m.size(); i++)
            ans.push_back(m[i]);

        return ans;
    }
    
    int dfs(TreeNode* root, unordered_map<int, vector<int>>& m) {
        
        int dep, left = 0, right = 0; 
        if (root->left)
            left = dfs(root->left, m)+1;
        if (root->right)
            right = dfs(root->right, m)+1;
        
        dep = max(left, right);
        m[dep].push_back(root->val);
        return dep;
    }
    
    // children depth + 1 
    
};