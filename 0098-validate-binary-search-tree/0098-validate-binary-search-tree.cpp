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
    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        long long minVal = (long long)INT_MIN-1;
        while(!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            
            cur = st.top(); st.pop();
            if (cur->val <= minVal) return false;
            minVal = cur->val;
            
            if (cur->right) cur = cur->right;
            else cur = NULL;
        }
        
        return true;
    }
};