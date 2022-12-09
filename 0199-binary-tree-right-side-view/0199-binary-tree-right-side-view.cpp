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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        vector<int> ans;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                if (size == 0) ans.push_back(cur->val);
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
        }
        return ans;
    }
};