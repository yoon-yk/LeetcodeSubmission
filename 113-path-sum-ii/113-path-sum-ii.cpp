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
    vector<vector<int>> ans;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        helper(root, targetSum, path);
        return ans;
    }
    
    void helper(TreeNode* root, int targetSum, vector<int> &path) {
        if (root == NULL) return;

        // leaf 에 도착하면 terminate
        if (root->left == NULL && root->right == NULL && targetSum == root->val) {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
            
        path.push_back(root->val);
        targetSum -= root->val;
        
        // exploration
        helper(root->left, targetSum, path);
        helper(root->right, targetSum, path);
        path.pop_back();
    }
};