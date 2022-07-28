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
        long long prev = LLONG_MIN;
        return inorderTraversal(root, prev);
    }
    
    bool inorderTraversal(TreeNode* root, long long& prev) {
        if (!root) return true;
        
        bool left = inorderTraversal(root->left, prev);
        
        if (root->val <= prev) return false;
        prev = root->val;
        
        bool right = inorderTraversal(root->right, prev);
        
        return left && right;
    }
};