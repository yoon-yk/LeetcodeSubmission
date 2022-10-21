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
        return isValid(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
    
    bool isValid(TreeNode* root, long lb, long ub){
        
        if (!root) return true;
        
        bool cur = (lb < root->val && root->val<ub);
        bool left = isValid(root->left, lb, root->val);
        bool right = isValid(root->right, root->val, ub);
        
        return (cur && left && right);
    }
};