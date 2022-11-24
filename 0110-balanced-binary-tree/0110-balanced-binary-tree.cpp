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
        if (calHeight(root) == -2)
            return false;
        return true;
    }
    
    int calHeight(TreeNode* root) {
        if (!root) return -1;
        
        int lHeight = calHeight(root->left);
        int rHeight = calHeight(root->right);
        
        if (lHeight == -2 || rHeight == -2 || 
            abs(lHeight-rHeight) > 1)
            return -2;

        return max(lHeight, rHeight) + 1;

    }
};