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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> rootQ;
        rootQ.push(root);
        
        int sizeQ;
        TreeNode* curr;
        
        while (!rootQ.empty()){
            sizeQ = rootQ.size();
            while (sizeQ--){
                curr = rootQ.front(); rootQ.pop();
                if (curr->left) rootQ.push(curr->left);
                if (curr->right) rootQ.push(curr->right);
            }
            ans.push_back(curr->val);
        }
        
        return ans;
    }
};