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
        
        stack<TreeNode*> tnST;
        TreeNode* curr = root;
        
        while(!tnST.empty() || curr) {
            
            while(curr) { // explore left
                tnST.push(curr);
                curr = curr->left;
            }
            
            curr = tnST.top(); tnST.pop(); // main node
            ans.push_back(curr->val);
            
            curr = curr->right; // right child
        }
        
        return ans;
    }
};