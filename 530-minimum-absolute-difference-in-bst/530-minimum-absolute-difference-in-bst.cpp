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
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        map<int, int> M;
        dfs(root, M);
        
        int prev = INT_MAX;
        for (auto cur:M) {
            if(cur.second > 1) {
                ans = 0;
                break;
            }
            ans = min(abs(cur.first - prev), ans);
            prev = cur.first;
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, map<int, int>& M) {
        if (!root) return;
        
        if (M.find(root->val)==M.end())
            M[root->val]++;
        else M[root->val] = 1;
        
        dfs(root->left, M);
        dfs(root->right, M);
    }
};