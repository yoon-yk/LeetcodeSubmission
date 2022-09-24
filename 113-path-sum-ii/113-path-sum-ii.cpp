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
        int curSum = 0;
        vector<int> curPath;
        vector<vector<int>> ans;
        
        if (!root) return {};
        
        curSum += root->val;
        curPath.push_back(root->val);
        backtrack(root, curSum, targetSum, curPath, ans);
        
        return ans;
    }
    
    void backtrack(TreeNode* root, int &curSum, const int targetSum, vector<int>& curPath, vector<vector<int>>& ans) {
        
        if (!root) return;
                
        // base case 
        if (!root->left && !root->right && curSum == targetSum) { 
            ans.push_back(curPath);
            return;
        }
        
        // children 
        if (root->left) {
            curSum += root->left->val;
            curPath.push_back(root->left->val);
            backtrack(root->left, curSum, targetSum, curPath, ans);
            curPath.pop_back();
            curSum -= root->left->val;
        }
        
        if (root->right) {
            curSum += root->right->val;
            curPath.push_back(root->right->val);
            backtrack(root->right, curSum, targetSum, curPath, ans);
            curPath.pop_back();
            curSum -= root->right->val;
        }
        
    }
};