class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        
        return matchSubtree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool matchSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        
        if (!root|| !subRoot) return false;
        
        return root->val == subRoot->val &&
            matchSubtree(root->left, subRoot->left) &&
            matchSubtree(root->right, subRoot->right);
    }
};