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
    bool isValidBST(TreeNode* root) {
        return helper(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
    
    bool helper(TreeNode* root, long minV, long maxV) {
        if (!root) return true;
        
        bool isRootValid = (root->val < maxV) && (minV < root->val);
        bool isLeftValid = helper(root->left, minV, root->val);
        bool isRightValid = helper(root->right, root->val, maxV);
        
        return isRootValid && isLeftValid && isRightValid;
    }
};