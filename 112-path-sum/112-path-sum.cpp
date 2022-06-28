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
    bool found = false;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==NULL) return false;
        
        stack<TreeNode*> st;
        st.push(root);
        
        TreeNode* cur;
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            
            if (!cur->left && !cur->right && cur->val == targetSum) {
                return true;
            }
            
            if (cur->left) {
                cur->left->val += cur->val;
                st.push(cur->left);
            }
            
            if (cur->right) {
                cur->right->val += cur->val;
                st.push(cur->right);
            }
            
        }
        
        return false;
    }
    
};