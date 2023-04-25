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
    
    int longestZigZag(TreeNode* root) {
        int maxPath = 0;
        dfs(root, maxPath);
        return maxPath;
    }
    
    pair<int, int> dfs(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return {-1, -1};
        }
        auto [ll, lr] = dfs(root->left, maxPath);
        auto [rl, rr] = dfs(root->right, maxPath);
        
        maxPath = max({maxPath, lr+1, rl+1});
        return {lr+1, rl+1};    
    }
};