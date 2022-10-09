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
    unordered_set<int> seen;
    
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        if (seen.count(k-root->val))
            return true;
        
        seen.insert(root->val);
        int ans = false;
        if (root->left) ans |= findTarget(root->left, k);
        if (root->right) ans |= findTarget(root->right, k);
        return ans;
    }
};