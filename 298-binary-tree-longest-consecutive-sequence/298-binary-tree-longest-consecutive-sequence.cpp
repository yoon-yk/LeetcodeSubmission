class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return helper(root, 1);
    }
    
    int helper(TreeNode* node, int length) {
        int best = length;
        if (node->left && node->left->val == node->val + 1)
            best = max(best, helper(node->left, length + 1));
        else if (node->left)
            best = max(best, helper(node->left, 1));
        
        if (node->right && node->right->val == node->val + 1)
            best = max(best, helper(node->right, length + 1));
        else if (node->right)
            best = max(best, helper(node->right, 1));

        return best;
    }
};