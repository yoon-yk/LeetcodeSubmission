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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        int curSum = 0;
        addNumbers(root, curSum);
        return ans;
    }
    
    void addNumbers(TreeNode* root, int curSum) {
        if (!root) return;        
        curSum = curSum*10 + root->val;
        if (!root->left && !root->right) ans += curSum;

        if (root->left) addNumbers(root->left, curSum);
        if (root->right) addNumbers(root->right, curSum);
    }
    
    
};