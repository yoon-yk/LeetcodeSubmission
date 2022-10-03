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
    int maxVal = 0;
    
    int longestConsecutive(TreeNode* root) {
        longestPath(root);
        return maxVal;
    }
    
    vector<int> longestPath (TreeNode* root) {
        if (root == NULL) 
            return {0, 0};
        
        int inr = 1, dcr = 1;
        if (root->left) {
            vector<int> left = longestPath(root->left);
            if (root->val == root->left->val + 1) {
                dcr = left[1] + 1;
            } else if (root->val == root->left->val -1) {
                inr = left[0] + 1;
            }
        }
        
        if (root->right) {
            vector<int> right = longestPath(root->right);
            if (root->val == root->right->val + 1) {
                dcr = max(right[1] + 1, dcr);
            } else if (root->val == root->right->val -1) {
                inr = max(right[0] + 1, inr);
            }
        }
        
        maxVal = max(maxVal, dcr+inr-1);
        return {inr, dcr};
        
    }
};