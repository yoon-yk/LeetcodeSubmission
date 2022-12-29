class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // find lca
        TreeNode* lca = getLCA(root, p, q);
        int distToP = calDist(lca, p);
        int distToQ = calDist(lca, q);
        
        return distToP+distToQ;
    }
    
    TreeNode* getLCA(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) 
            return root;
        
        TreeNode* left = getLCA(root->left, p, q);
        TreeNode* right = getLCA(root->right, p, q);
        
        if (left && right) return root;
        else if (left) return left;
        return right;
    }
    
    int calDist(TreeNode* root, int target){
        if (!root) return -1;
        
        if (root->val == target) return 0;
        
        int left = calDist(root->left, target);
        int right = calDist(root->right, target);
        
        if (left >= 0) return left+1;
        else if (right >= 0) return right + 1;
        return -1;
    }
};