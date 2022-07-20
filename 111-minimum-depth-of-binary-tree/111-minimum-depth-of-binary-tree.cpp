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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> nodeQ;
        
        root->val = 1;
        nodeQ.push(root);
        
        TreeNode* curr;
        int dep = INT_MAX;
        while(!nodeQ.empty()) {
            curr = nodeQ.front();
            nodeQ.pop();
            
            if(!curr->left && !curr->right) {
                dep = min(dep, curr->val);
                break;
            }
            
            if(curr->left) {
                curr->left->val = curr->val + 1;
                nodeQ.push(curr->left);
            }
            
            
            if(curr->right) {
                curr->right->val = curr->val + 1;
                nodeQ.push(curr->right);
            }
            
        }
        return dep;
    }
};