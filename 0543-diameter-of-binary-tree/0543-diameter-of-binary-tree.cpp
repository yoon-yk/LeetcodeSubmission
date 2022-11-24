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
    int maxD = 0;
    int diameterOfBinaryTree(TreeNode* root) {

        getMaxDistance(root);
        return maxD;
    }
    
    int getMaxDistance(TreeNode* root) {
        if (!root) return 0;
        
        int leftD = getMaxDistance(root->left)+1;
        int rightD = getMaxDistance(root->right)+1;
        
        maxD = max(maxD, leftD + rightD - 2);
        return max(leftD, rightD);
    }
};