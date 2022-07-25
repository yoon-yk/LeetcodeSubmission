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
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        return inorderTraverse(root, prev);
    }
    
    int inorderTraverse(TreeNode* root, int &prev) { // time - O(N), space - O(H) for stack recursion
        
        int minDiff = INT_MAX;
        
        // left child
        if (root->left)
            minDiff = min(minDiff, inorderTraverse(root->left, prev));

        // root
        if (prev >= 0)
            minDiff = min((root->val)-prev, minDiff);
        prev = root->val;

        // right child
        if (root->right)
            minDiff = min(minDiff, inorderTraverse(root->right, prev));

        // return minimum difference
        return minDiff;
    }
};