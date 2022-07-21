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
        
        string s_path, d_path;
        findPath(root, startValue, s_path);
        findPath(root, destValue, d_path);
        
        while(!s_path.empty()&&!d_path.empty()
            &&(s_path.back()==d_path.back())){
            s_path.pop_back(); d_path.pop_back();
        }
        
        return string(s_path.size(), 'U') + string(rbegin(d_path), rend(d_path)); 
    }
    
    bool findPath(TreeNode* root, int& target, string& path) {
        
        if (root->val == target) return true;
        
        if (root->left && findPath(root->left, target, path)) {
            path.push_back('L');
        }
        else if (root->right && findPath(root->right, target, path)) {
            path.push_back('R');
        }
        return !path.empty();
    }
    
};