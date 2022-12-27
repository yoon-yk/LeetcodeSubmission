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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) Q.push(root);
        
        int size, sum;
        while (!Q.empty()) {
            size = Q.size();
            sum = 0;
            while (size--) {
                auto cur = Q.front(); Q.pop();
                sum += cur->val;
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
        }
        return sum;
    }
};