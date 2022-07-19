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

        path.push_back(root->val);

        // leaf 에 도착하면 terminate
        if (root->left == NULL && root->right == NULL && targetSum == root->val) {
            ans.push_back(path);
        }
        
        // exploration
        else {
            helper(root->left, targetSum-root->val, path);
            helper(root->right, targetSum-root->val, path);
        }

        path.pop_back();
    }
};