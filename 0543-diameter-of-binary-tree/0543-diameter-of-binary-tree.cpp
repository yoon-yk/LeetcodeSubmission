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
        
        int leftD = getMaxDistance(root->left);
        int rightD = getMaxDistance(root->right);
        
        maxD = max(maxD, leftD + rightD);
        return max(leftD, rightD) + 1;
    }
};