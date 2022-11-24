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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            
            TreeNode* newL = cur->right;
            TreeNode* newR = cur->left;
            
            cur->left = newL;
            cur->right = newR;
            
            if (cur->left) Q.push(cur->left);
            if (cur->right) Q.push(cur->right);
        }
        
        return root;
    }
};