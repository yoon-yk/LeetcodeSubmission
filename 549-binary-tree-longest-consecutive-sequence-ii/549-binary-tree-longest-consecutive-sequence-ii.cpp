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
        vector<int> res = {0, 0};
        longestPath(root, res);
        return maxVal;
    }
    
    void longestPath (TreeNode* root, vector<int>& res) {
        if (root == NULL) 
            return;
        
        int inr = 1, dcr = 1;
        if (root->left) {
            longestPath(root->left, res);
            if (root->val == root->left->val + 1) {
                dcr = res[1] + 1;
            } else if (root->val == root->left->val -1) {
                inr = res[0] + 1;
            }
        }
        
        if (root->right) {
            longestPath(root->right, res);
            if (root->val == root->right->val + 1) {
                dcr = max(res[1] + 1, dcr);
            } else if (root->val == root->right->val -1) {
                inr = max(res[0] + 1, inr);
            }
        }
        
        maxVal = max(maxVal, dcr+inr-1);
        res[0] = inr, res[1] = dcr;
        
    }
};