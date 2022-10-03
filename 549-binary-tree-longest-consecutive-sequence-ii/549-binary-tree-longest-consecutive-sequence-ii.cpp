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
        int curInc = 0, curDec = 0;
        longestPath(root, curInc, curDec);
        return maxVal;
    }
    
    void longestPath (TreeNode* root, int& curInc, int& curDec) {
        if (root == NULL) 
            return;
        
        int inc = 1, dec = 1;
        if (root->left) {
            longestPath(root->left, curInc, curDec);
            if (root->val == root->left->val + 1)
                dec = curDec + 1;
            else if (root->val == root->left->val -1)
                inc = curInc + 1;
            
        }
        
        if (root->right) {
            longestPath(root->right, curInc, curDec);
            if (root->val == root->right->val + 1)
                dec = max(curDec + 1, dec);
            else if (root->val == root->right->val -1)
                inc = max(curInc + 1, inc);
        }
        
        maxVal = max(maxVal, dec+inc-1);
        curInc = inc, curDec = dec;
    }
};