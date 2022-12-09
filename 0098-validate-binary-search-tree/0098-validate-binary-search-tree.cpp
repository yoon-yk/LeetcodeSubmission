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
        return isValid(root, (long long)INT_MIN-1, (long long)INT_MAX+1);
    }
    
    bool isValid(TreeNode*root, long long minV, long long maxV) {
    
        if (!root) return true;
        
        bool isRootValid = (root->val < maxV && minV < root->val);
        bool isLeftValid = isValid(root->left, minV, root->val);
        bool isRightValid = isValid(root->right, root->val, maxV);
        
        return isRootValid && isLeftValid && isRightValid;
    }
};