class Solution {
public:
    string getDirections(TreeNode* root, int srcV, int dstV) {
        // find the root
        TreeNode* lca = getLCA(root, srcV, dstV);
        string pathToP, pathToQ;
        getPath(lca, srcV, pathToP);
        getPath(lca, dstV, pathToQ);
        reverse(pathToQ.begin(), pathToQ.end());
        return string(pathToP.size(), 'U') + pathToQ;
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
    
    bool getPath(TreeNode* root, int target, string& path){
        if (!root) return false;
        
        if (root->val == target) return true;
        
        bool left = false, right = false;
        if (left = getPath(root->left, target, path)) {
            path += 'L';
        }
        
        if (right = getPath(root->right, target, path)) {
            path += 'R';
        }
        
        return (left | right);
        
    }
};