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
    int closestValue(TreeNode* root, double target) {
        TreeNode* ret = traverse(root, target);
        if (ret) return ret->val;
        return -1;
    }
    
    TreeNode* traverse(TreeNode* root, double target) {
        
        if (!root) return NULL; 
        
        TreeNode* ret = root, *left = NULL, *right = NULL;
        
        if (target < root->val && root->left) {
            left = traverse(root->left, target);
        }
        
        if (root->val < target && root->right) {
            right = traverse(root->right, target);
        }
        
        if (left && abs(left->val-target) < abs((double)(ret->val-target))) ret = left;
        if (right && abs(right->val-target) < abs((double)(ret->val-target))) ret = right;
        return ret;
    }
    
};