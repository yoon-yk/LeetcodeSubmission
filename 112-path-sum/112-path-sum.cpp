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
    bool found = false;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        calSum(root, targetSum, 0);
        return found;
    }
    
    void calSum(TreeNode* root, int targetSum, int sum) {
        if (root==NULL) return;
        sum = sum+root->val;
        
        if (!root->left && !root->right && sum == targetSum) {
            found=true;
            return;
        }
        
        calSum(root->left, targetSum, sum);
        calSum(root->right, targetSum, sum);
    }
};