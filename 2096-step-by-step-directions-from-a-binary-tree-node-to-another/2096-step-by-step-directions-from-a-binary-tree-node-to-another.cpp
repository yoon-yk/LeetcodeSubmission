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
    string ans;
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lcaRoot = LCA(root, startValue, destValue);
        
        string finalSPath = "", finalEPath = "";
        findPath(lcaRoot, startValue, true, finalSPath);
        findPath(lcaRoot, destValue, false, finalEPath);
        
        ans += finalSPath;
        ans += finalEPath;
        
        return ans;
    }
    
    void findPath (TreeNode* root, int target, bool isStart, string &path) {
        if (!root) return;
        
        if (root->val == target) {
            if (isStart) {
                ans = path + ans;
            }
            else {
                ans = ans + path;
            }
            return;
        }
        
        if (isStart){
            
            path+="U";
            findPath(root->left, target, isStart, path);
            findPath(root->right, target, isStart, path);
            path.pop_back();
        }
        else {
            path+="L";
            findPath(root->left, target, isStart, path);
            path.pop_back();
            path+="R";
            findPath(root->right, target, isStart, path);
            path.pop_back();
        }

    }
        
    TreeNode* LCA(TreeNode* root, int startValue, int destValue) {
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