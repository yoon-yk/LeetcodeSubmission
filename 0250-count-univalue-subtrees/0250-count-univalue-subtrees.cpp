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
    int ans = 0;
    int countUnivalSubtrees(TreeNode* root) {
        univalue(root);
        return ans;
    }
    
    int univalue(TreeNode* root) {
        
        if (!root) return 2000;
        
        int left = (root->left) ? univalue(root->left) : root->val;
        int right = (root->right) ? univalue(root->right) : root->val;
        
        if (left == root->val && root->val == right) {
            ++ans;
            return root->val;
        }
        
        return 2000;
        
    }
    
    
};