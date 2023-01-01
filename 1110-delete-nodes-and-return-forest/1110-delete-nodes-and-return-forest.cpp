/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<int> dels;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dels.insert(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        dfs(root, ans);
        if (root) ans.push_back(root);
        return ans;
    }
    
    void dfs(TreeNode*& root, vector<TreeNode*>& ans) {
        if (!root) return;
        
        dfs(root->left, ans);
        dfs(root->right, ans);
        
        if (dels.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            root = NULL;
        }
        
    }
};