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
    TreeNode* pruneTree(TreeNode* root) {
        if (!isOneContained(root))
            root = NULL;
        return root;
    }
    
    bool isOneContained(TreeNode* root) {
        
        if (!root) return false;
        
        if (!root->left && !root->right)
            return root->val == 1;
        
        bool left = isOneContained(root->left);
        bool right = isOneContained(root->right);
        
        if (!left) root->left = NULL;
        if (!right) root->right = NULL;
        
        return (root->val == 1 || left || right);
    }
};