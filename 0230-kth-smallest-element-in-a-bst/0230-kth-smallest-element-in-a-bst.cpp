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
    int kthSmallest(TreeNode* root, int k) {
        // preorder
        stack<TreeNode*> st;
        
        int cnt = 0;
        TreeNode* cur = root;
        while (!st.empty() || cur) {

            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            
            cur = st.top(); st.pop();
            if (++cnt == k)
                return cur->val;
            
            if (cur->right) cur = cur->right;
            else cur = NULL;
        }
        
        return -1;
        
    }
};