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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot) ||
            isSameTree(root, subRoot);
    }
    
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        else if (!a || !b) return false;
        return (a->val == b->val) && isSameTree(a->left, b->left) 
            && isSameTree(a->right, b->right);
    }
};