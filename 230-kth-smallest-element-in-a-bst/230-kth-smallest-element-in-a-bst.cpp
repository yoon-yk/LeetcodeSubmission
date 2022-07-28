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
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> tnST;
        TreeNode* curr = root;
        int cnt = 0;
        
        while(!tnST.empty() || curr) {
            
            while (curr) {
                tnST.push(curr);
                curr = curr->left;
            }
            
            curr = tnST.top(); tnST.pop();
            if(++cnt == k) break;
            
            curr = curr->right;
            
        }
        
        return curr->val;
    }
};