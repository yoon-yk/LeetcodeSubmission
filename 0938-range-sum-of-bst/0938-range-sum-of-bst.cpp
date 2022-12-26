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
    
    // preorder 
    int rangeSumBST(TreeNode* root, int low, int high) {
        // preorder
        if (!root) return 0;
        
        int sum = 0;
        if (root->left && low < root->val) sum += rangeSumBST(root->left, low, high);
        
        if (low <= root->val && root->val <= high) 
            sum += root->val;
        
        if (root->right && root->val < high) sum += rangeSumBST(root->right, low, high);
            
        return sum;
    }
    
};