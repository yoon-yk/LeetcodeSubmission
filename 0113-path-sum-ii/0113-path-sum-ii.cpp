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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curPath;
        vector<vector<int>> ans;
        if (!root) return ans;
        curPath.push_back(root->val);
        traverse(root, targetSum-root->val, curPath, ans);
        return ans;
    }
    
    void traverse(TreeNode* root, int target, vector<int>& curPath, vector<vector<int>>& ans) {
        if (!root) return;
        
        if (!root->left && !root->right && target == 0){
            ans.push_back(curPath);
            return;
        } 
            
        if (root->left) {
            curPath.push_back(root->left->val);
            traverse(root->left, target - root->left->val, curPath, ans);
            curPath.pop_back();
        }
        if (root->right) {
            curPath.push_back(root->right->val);
            traverse(root->right, target - root->right->val, curPath, ans);
            curPath.pop_back();
        }
        
    }
};