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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        
        string curStr;
        backtrack(root, curStr, ans);
        return ans;
    }
    
    void backtrack(TreeNode* root, string& curStr, vector<string>& ans) {
        
        curStr += to_string(root->val);
        int origLen = curStr.size(), newLen;

        if (!root->left && !root->right) {
            ans.push_back(curStr);
            return;
        } 
        
        if (root->left) {
            curStr += "->";
            backtrack(root->left, curStr, ans);
            newLen = curStr.size();
            for (int i=0; i<newLen-origLen; ++i) curStr.pop_back();
        }
        
        if (root->right) {
            curStr += "->";
            backtrack(root->right, curStr, ans);
            newLen = curStr.size();
            for (int i=0; i<newLen-origLen; ++i) curStr.pop_back();
        }
        
    }
};