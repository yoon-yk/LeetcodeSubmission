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

using pii = pair<int, int>;
class Solution {
public:
    int ans = 0;
    pii getSumAndCount(TreeNode* root) {
        if (root == NULL) return {0, 0}; // s, c

        int sum = root->val;
        int cnt = 1;

        pii l = {0, 0}, r = {0, 0};
        if (root->left) 
            l = getSumAndCount(root->left);
        if (root->right) 
            r = getSumAndCount(root->right);

        sum += l.first + r.first;
        cnt += l.second + r.second;

        ans += (root->val == (sum / cnt));

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        getSumAndCount(root);

        return ans;
    }
};