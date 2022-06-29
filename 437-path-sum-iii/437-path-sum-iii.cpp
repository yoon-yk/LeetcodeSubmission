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
typedef long long int lli;

class Solution {
public:
    
    
    int pathSum(TreeNode* root, long long int targetSum) {
        if (root == NULL) return 0;
        
        lli count = 0;
        
        helper(root, targetSum, count);

        return count + 
            pathSum(root->left, targetSum) +
            pathSum(root->right, targetSum);
    }
    
    lli helper(TreeNode* root, lli targetSum, lli& count) {
                
        if (root == NULL) return 0 ;
        if (root->val == targetSum) count++;

        return count + 
            helper(root->left, targetSum-root->val, count) + 
            helper(root->right, targetSum-root->val, count);
    }
};