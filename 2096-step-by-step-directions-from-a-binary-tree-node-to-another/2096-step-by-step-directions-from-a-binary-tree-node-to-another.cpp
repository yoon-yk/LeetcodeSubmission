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
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lcaRoot = LCA(root, startValue, destValue);
        
        string finalSPath = "", finalDPath = "";
        findPath(lcaRoot, startValue, true, finalSPath);
        findPath(lcaRoot, destValue, false, finalDPath);

        return finalSPath+finalDPath;
    }
    
    bool findPath (TreeNode* root, int& target, bool isStart, string& path) {
        if (!root) return false;
        
        if (root->val == target) return true;
        
        if (isStart){
            path+="U";
            if ((root->left && findPath(root->left, target, isStart, path)) ||
                (root->right && findPath(root->right, target, isStart, path))) return true;
            path.pop_back();
        }
        else {
            path+="L";
            if (root->left && findPath(root->left, target, isStart, path)) return true;
            path.pop_back();
            
            path+="R";
            if (root->right && findPath(root->right, target, isStart, path)) return true;
            path.pop_back();
        }
        
        return false;

    }
        
    TreeNode* LCA(TreeNode* root, int& startValue, int& destValue) {
        if (!root) return root;
        if (root->val == startValue) return root;
        if (root->val == destValue) return root;
        
        TreeNode* left = LCA(root->left, startValue, destValue);
        TreeNode* right = LCA(root->right, startValue, destValue);

        if (!left) return right;
        if (!right) return left;
        
        return root;
    }
};