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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> tnST;
        TreeNode* curr = root;
        long long prev = LLONG_MIN;
        
        while (!tnST.empty() || curr) {
            while (curr) { // left
                tnST.push(curr);
                curr = curr->left;
            }
            
            curr = tnST.top(); tnST.pop(); // pop from the stack and 
            if (curr->val <= prev) return false; // check the mid
            prev = curr->val; 
            
            // update curr to curr->right
            curr = curr->right;
        }
        
        return true;
    }
};