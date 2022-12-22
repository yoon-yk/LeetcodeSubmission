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
        findLeaves(root, ans);
        
        return ans;
    }
    
    int findLeaves(TreeNode* root, vector<vector<int>>& ans) {
        if (!root) return 0;
        
        int distToLeaves = findLeaves(root->left, ans);
        distToLeaves = max(distToLeaves, findLeaves(root->right, ans));
        
        if (ans.size() == distToLeaves) ans.push_back({});
        ans[distToLeaves].push_back(root->val);
        
        return distToLeaves+1;
        
    }
    
};