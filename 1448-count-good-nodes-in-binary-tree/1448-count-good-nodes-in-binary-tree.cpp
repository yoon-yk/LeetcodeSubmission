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
        int maxVal = INT_MIN;
        return dfs(root, maxVal);
    }
    
    int dfs(TreeNode* root, int maxVal) {
        
        int cnt = 0;
        if (!root) return cnt;
        
        if (root->val >= maxVal) {
            cnt ++;
            maxVal = root->val;
        }
        
        cnt += dfs(root->left, maxVal);
        cnt += dfs(root->right, maxVal);
        
        return cnt;
    }
};