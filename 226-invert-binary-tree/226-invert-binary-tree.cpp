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
        if (!root) return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* cur = nullptr;
        TreeNode* tmpL = nullptr, *tmpR = nullptr;
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            
            tmpL = cur->left;
            tmpR = cur->right;
            
            cur->left = tmpR;
            cur->right = tmpL;
        }
        
        return root;
    }
};