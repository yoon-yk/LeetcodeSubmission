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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& ans) {
        if (!root) return -1;
        
        int left = dfs(root->left, ans)+1;
        int right = dfs(root->right, ans)+1;
        
        if (ans.size() == max(left, right)) ans.push_back({});
        ans[max(left, right)].push_back(root->val);
        
        return max(left, right);
    }
};