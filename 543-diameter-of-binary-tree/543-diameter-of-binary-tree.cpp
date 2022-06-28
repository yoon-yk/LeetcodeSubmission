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
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (root==NULL) return 0;
        
        int maxD = max(diameterOfBinaryTree(root->left), 
                       diameterOfBinaryTree(root->right));
        
        return max(depth(root->left, 0) + depth(root->right, 0), maxD);
    }
    
    int depth(TreeNode* root, int height){
        
        if (root==NULL) return height;
        
        int left = depth(root->left, height+1);
        int right = depth(root->right, height+1);
        
        return max(left, right);
    }
};