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
    int maxD = INT_MIN;
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (root==NULL) return 0;
        
        depth(root, 0);
        
        return maxD;
    }
    
    int depth(TreeNode* root, int height){
        
        if (root==NULL) return 0;
        
        int left = depth(root->left, height);
        int right = depth(root->right, height);
        
        maxD = max(maxD, left+right);
        
        return max(left, right)+1;
    }
};