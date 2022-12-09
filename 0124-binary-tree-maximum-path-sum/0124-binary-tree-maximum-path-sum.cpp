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
    int maxSum = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        getPathSum(root);
        return maxSum;
    }
    
    int getPathSum(TreeNode* root) {
        if (!root) return 0;
        
        int left = 0, right = 0;
        
        left = max(getPathSum(root->left), 0);
        right = max(getPathSum(root->right), 0);
        
        maxSum = max(maxSum, left + right + root->val);
        
        return max(left+root->val, right+root->val);
    }

    /*
    root itself
    left to root
    right to root
    left to right
    */
};