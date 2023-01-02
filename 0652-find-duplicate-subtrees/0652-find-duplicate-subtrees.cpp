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
    unordered_map<string, int> mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        serialize(root, ans);
        return ans;
    }
    
    string serialize(TreeNode* root, vector<TreeNode*>& ans) {
        if (!root) return "#";
        string s = to_string(root->val) + ',';
        s += serialize(root->left, ans) + ',';
        s += serialize(root->right, ans);
        
        if (++mp[s] == 2)
            ans.push_back(root);
        return s;
    }
};