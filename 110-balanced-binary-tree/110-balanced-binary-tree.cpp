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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        dfsHeight(root);
        return (root->val != -1);
    }
    
    void dfsHeight(TreeNode* root) {
        if (!root) return;
        dfsHeight(root->left);
        dfsHeight(root->right);
        int left = (root->left)? root->left->val : 0;
        int right = (root->right)? root->right->val : 0;
        root->val = (left == -1 || right == -1 || abs(left-right) > 1) ?
            -1 : max(left, right)+1;
    }
};