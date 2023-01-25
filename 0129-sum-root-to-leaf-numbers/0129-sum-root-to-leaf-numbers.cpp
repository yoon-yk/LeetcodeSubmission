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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        addNumbers(root, 0, ans);
        return ans;
    }
    
    void addNumbers(TreeNode* root, int curSum, int& ans) {
        if (!root) return;        
        curSum = curSum*10 + root->val;
        if (!root->left && !root->right) ans += curSum;

        if (root->left) addNumbers(root->left, curSum, ans);
        if (root->right) addNumbers(root->right, curSum, ans);
    }
    
    
};