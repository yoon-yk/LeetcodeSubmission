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
        
        dfs(root, to_string(root->val));
        
        return ans;
    }
    
    void dfs(TreeNode* root, string currPath) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(currPath);
        }
        else {
            if(root->left)dfs(root->left, currPath+ "->" + to_string(root->left->val));  
            if(root->right)dfs(root->right, currPath+ "->" + to_string(root->right->val));            
        }
        
    }
};