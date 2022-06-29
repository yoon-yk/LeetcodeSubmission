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

typedef long long int lli;

class Solution {
public:
    
    lli pathSum(TreeNode* root, lli targetSum) {
        if (root == NULL) return 0;
        lli path = 0;
        helper(root, targetSum, 0, path);
        path += pathSum(root->left, targetSum);
        path += pathSum(root->right, targetSum);
        return path;
        
    }
    
    void helper(TreeNode* root, lli targetSum, lli curSum, lli& path){
        if (root == NULL) return;
        
        if (curSum+root->val == targetSum) path++;
        
        helper(root->left, targetSum, curSum+root->val, path);
        helper(root->right, targetSum, curSum+root->val, path);
    }
};