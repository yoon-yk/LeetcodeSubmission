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
    string smallestFromLeaf(TreeNode* root) {
        
        if (!root) return "";
        
        helper(root, "");
        sort(ans.begin(), ans.end());
        
        return ans[0];
    }
    
    void helper(TreeNode* root, string currStr) {
        if (!root) return;
        
        currStr = (char)(root->val+97) + currStr;
        
        if (!root->left && !root->right) {
            ans.push_back(currStr);    
        }
        else {
            helper(root->left, currStr);
            helper(root->right, currStr);
        }
    }
};