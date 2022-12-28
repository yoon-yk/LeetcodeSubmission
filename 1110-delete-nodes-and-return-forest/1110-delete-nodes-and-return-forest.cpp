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
    vector<TreeNode*> ans;
    unordered_set<int> del;
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        del.insert(to_delete.begin(), to_delete.end());
        dfs(root);
        if (root) ans.push_back(root);
        return ans;
    }
    
    void dfs(TreeNode*& root) {
        if (!root) return;
        
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);      
        
        if (del.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            root = NULL;
        }
    }
};