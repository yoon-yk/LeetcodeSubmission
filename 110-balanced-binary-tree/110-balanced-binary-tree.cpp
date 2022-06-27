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
        
        int lHeight = calHeight(root->left, 1);
        int rHeight = calHeight(root->right, 1);
        int diff = abs(calHeight(root->left, 1) - calHeight(root->right, 1));
        
        return (diff <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int calHeight(TreeNode* root, int height) {
        if (!root) return height;
        
        return max(calHeight(root->left, height+1), 
                   calHeight(root->right, height+1));
    }
};
    