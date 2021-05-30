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
    bool checkBST(TreeNode* root, long min, long max){
        bool left=true, right=true;
        if(!root) return true; // if empty root
        if(root->left)
            left = checkBST(root->left, min,root->val);
        if(root->right)
            right = checkBST(root->right, root->val, max);
        return (root->val<max)&&(min<root->val)&&left&&right;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long MIN_INT = - 2147483648;
        long MAX_INT = 2147483647;
        return checkBST(root, MIN_INT-1, MAX_INT+1);
    }
};