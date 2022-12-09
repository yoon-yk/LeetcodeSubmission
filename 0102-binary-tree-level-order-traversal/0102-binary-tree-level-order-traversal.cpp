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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> ans;
        if (root) Q.push(root);
        
        int idx=0;
        while (!Q.empty()) {
            
            int size = Q.size();
            ans.push_back({});
            while (size--) {
                auto cur = Q.front(); Q.pop();
                ans[idx].push_back(cur->val);
                
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            idx++;
        }
        
        return ans;
    }
};