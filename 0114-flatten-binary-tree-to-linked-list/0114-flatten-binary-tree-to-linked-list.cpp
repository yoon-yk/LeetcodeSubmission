class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode* node = root;
        
        while (node) {
            if (node->left) {
                TreeNode* rightmost = node->left;
                while(rightmost->right) {
                    rightmost = rightmost->right;
                }
                rightmost->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};