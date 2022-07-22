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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode*> intST;
        
        TreeNode* curr = root;
        
        while (curr || !intST.empty()) {
            
            while (curr) {
                intST.push(curr);
                curr = curr->left;
            }
            
            curr = intST.top(); intST.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        
        return ans;
    }
};