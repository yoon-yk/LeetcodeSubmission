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
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool helper(TreeNode* root, long long lowerbound, long long upperbound){
        if (!root) return true;
        
        bool left = !(root->left) || 
                        (root->left && root->left->val < root->val 
                        && helper(root->left, lowerbound, root->val));
        bool right = !(root->right) || 
                        (root->right && root->val < root->right->val 
                        && helper(root->right, root->val, upperbound));
        
        return lowerbound < root->val && root->val < upperbound && left && right;
    }
};