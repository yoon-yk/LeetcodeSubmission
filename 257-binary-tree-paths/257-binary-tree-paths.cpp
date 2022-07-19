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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if (!root) return ans;
        string rootStr = to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(rootStr);
        }
        dfs(root->left, rootStr);
        dfs(root->right, rootStr);
        
        return ans;
    }
    
    void dfs(TreeNode* root, string currPath) {
        if (!root) return;
    
        currPath += "->" + to_string(root->val);
        
        if (!root->left && !root->right) {
            ans.push_back(currPath);
        }
        else {
            dfs(root->left, currPath);  
            dfs(root->right, currPath);            
        }
        
    }
};