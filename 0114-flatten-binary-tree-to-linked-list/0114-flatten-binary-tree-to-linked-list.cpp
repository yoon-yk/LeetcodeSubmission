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
    void flatten(TreeNode* root) {
        // preorder 
        if (!root) return;
        
        TreeNode* dHead = new TreeNode();
        dHead->right = root;
        TreeNode* ptr = dHead;
        preorder(root, ptr);

    }
    
    void preorder(TreeNode* root, TreeNode*& ptr) {
        // preorder 
        if (!root) return;
        
        ptr->right = root;
        ptr = ptr->right;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = root->right = NULL;
        
        if (left)
            preorder(left, ptr);
        if (right) 
            preorder(right, ptr);
    }
};