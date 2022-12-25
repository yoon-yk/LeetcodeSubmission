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
    string getDirections(TreeNode* root, int sV, int dV) {
        TreeNode* lca = findLCA (root, sV, dV);
        string pathToSrc, pathToDes;
        findPath(lca, sV, pathToSrc);
        findPath(lca, dV, pathToDes);
        reverse(pathToDes.begin(), pathToDes.end());
        return string(pathToSrc.size(), 'U') + pathToDes;
    }
    
    bool findPath(TreeNode* root, int target, string& path) {
        if (!root) return false;
        if (root->val == target) return true;
        
        bool ans = false;
        if (findPath(root->left, target, path)) {
            path += 'L';
            ans = true;
        }
        else if (findPath(root->right, target, path)) {
            path += 'R';
            ans = true;
        }
        
        return ans;
    }
    
    TreeNode* findLCA (TreeNode* root, int srcV, int dstV) {
        if (!root || root->val == srcV || root->val == dstV) return root;
        
        TreeNode* left = findLCA (root->left, srcV, dstV);
        TreeNode* right = findLCA (root->right, srcV, dstV);
        
        if (left && right) return root;
        else if (left) return left;
        return right;
    }
};