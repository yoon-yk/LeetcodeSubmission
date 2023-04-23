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

/*
    1
  2   3
 4      7

*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        queue<pair<TreeNode*, int>> Q;
        if (root) Q.push({root, 0});
        while (!Q.empty()) {            
            int minV = INT_MAX, maxV = INT_MIN;
            int size = Q.size();
            int offset = Q.front().second;
            for (int i=1; i<=size; ++i) {
                auto [cur, cnt] = Q.front(); Q.pop();
                cnt -= offset;
                minV = min(minV, cnt);
                maxV = max(maxV, cnt);
                
                if (cur->left) {
                    Q.push({cur->left, cnt<<1});
                }
                
                if (cur->right) {
                    Q.push({cur->right, (cnt<<1) + 1});
                }
            }
            
            if (maxV != INT_MIN && minV != INT_MAX)
                ans = max(ans, maxV-minV+1);        
        }
        return ans;
    }
    
};