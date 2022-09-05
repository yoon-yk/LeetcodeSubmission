class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = longestConsecutive(root->left);
        int r = longestConsecutive(root->right);
        int lr = max(l,r);
        int gval = g(root);
        return max(gval, lr);
    }
private:
    //the length of the longest consecutive sequence path starting from root
    int g(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = 0, r = 0;
        if(root->left && root->val + 1 == root->left->val) 
            l = g(root->left);
        if(root->right && root->val + 1 == root->right->val) 
            r = g(root->right);
        return 1 + max(l,r);
    }
};