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
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;
        queue<TreeNode*> Q;
        if (root) Q.push(root);

        while (!Q.empty()) {
            int size = Q.size();
            int maxElm = Q.front()->val;
            while (size--) {
                auto cur = Q.front(); Q.pop();
                maxElm = max(maxElm, cur->val);
                
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            ans.push_back(maxElm);
        }

        return ans;
    }
};