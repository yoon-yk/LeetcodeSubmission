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
    
    lli pathSum(TreeNode* root, lli targetSum) {
        if (root == NULL) return 0;
        
        lli count = 0;
        count += helper(root, targetSum);

        return count + 
            pathSum(root->left, targetSum) +
            pathSum(root->right, targetSum);
    }
    
    lli helper(TreeNode* root, lli targetSum) {
        
        lli count = 0;
        if (root == NULL) return count;
        if (root->val == targetSum) count++;

        return count 
            + helper(root->left, targetSum-root->val)
            + helper(root->right, targetSum-root->val);

    }
};