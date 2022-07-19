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

typedef long long ll;

class Solution {
public:
    ll cnt = 0;
    ll pathSum(TreeNode* root, ll targetSum) {
        if (!root) return cnt;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return cnt;
    }
    
    void dfs(TreeNode* root, ll targetSum) {
        if (!root) return;
        
        if (targetSum == root->val) cnt++;
        
        dfs(root->left, targetSum-root->val);
        dfs(root->right, targetSum-root->val);
    }
};