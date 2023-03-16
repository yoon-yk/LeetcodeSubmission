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
    int leftCnt, rightCnt;

    int dfs(TreeNode* root, int x) {
        if (!root) return 0;
        
        int left = dfs(root->left, x);
        int right = dfs(root->right, x);
        
        if (root->val == x) {
            leftCnt = left, rightCnt = right;
        }
        
        return left+right+1;
        
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        leftCnt = rightCnt = 0;
        
        dfs(root, x);
        int maxCount = max({leftCnt, rightCnt, n-(leftCnt+rightCnt+1)});
        
        return maxCount > (n >> 1);
    }
};