/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        TreeNode *prev = root, *curr=root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            curr = st.top(); st.pop();
            if (isNodeFound(curr, p->val) && isNodeFound(curr, q->val)) {
                prev = curr;
                st.push(curr->left); st.push(curr->right);
            }
        }
        return prev;
    }
    
    bool isNodeFound(TreeNode* root, int target){
        if (!root) return false;
        if (root->val == target)
            return true;        
        return isNodeFound(root->left, target) || isNodeFound(root->right, target);
    }
};