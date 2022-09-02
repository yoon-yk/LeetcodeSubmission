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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<double> ans;
        Q.push(root);
        
        int size, cnt;
        double curAver;
        TreeNode* cur;
        
        while (!Q.empty()) {
            size = cnt = Q.size();
            curAver = 0;
            while (cnt--) {
                // approach by level
                cur = Q.front(); Q.pop();
                curAver += (double) cur->val;
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            curAver /= (double)size;
            ans.push_back(curAver);
        }
        
        return ans;
    }
};