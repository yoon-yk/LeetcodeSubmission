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
    int goodNodes(TreeNode* root) {
       return isGoodNodes(root, -99999); 
    }
    
    int isGoodNodes(TreeNode* root, int maxElm) {
        
        if (!root) return 0;
        
        int ans = (root->val >= maxElm);
        maxElm = max(root->val, maxElm);
        
        if (root->left) ans += isGoodNodes(root->left, maxElm);
        if (root->right) ans += isGoodNodes(root->right, maxElm);
        
        return ans;
        
    }
};