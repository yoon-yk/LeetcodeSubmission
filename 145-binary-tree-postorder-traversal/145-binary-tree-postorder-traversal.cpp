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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode*> tnST;
        TreeNode* curr = root;
        TreeNode* tmp = NULL;
        
        while (!tnST.empty() || curr) {
        
            // left 
            while (curr) {
                tnST.push(curr);
                curr = curr->left;
            }

            curr = tnST.top(); 
            tnST.pop();
            
            if (!curr->right) {
                tmp = NULL;
                ans.push_back(curr->val);    
            }
            
            else {
                tmp = curr->right;
                curr->right = NULL;
                tnST.push(curr);    
            }

            curr = tmp;
        }

        return ans;
    }
};