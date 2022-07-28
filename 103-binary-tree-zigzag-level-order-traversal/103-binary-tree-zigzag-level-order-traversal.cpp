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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if (!root) return {};
        
        vector<vector<int>> ans;
        stack<TreeNode*> oddST;
        stack<TreeNode*> evenST;
        oddST.push(root);
        int level = 1;
        
        int stackSize;
        TreeNode* curr;
        while (!oddST.empty() || !evenST.empty()) {
            
            vector<int> currVec;
            
            if (level % 2){ // odd
                stackSize = oddST.size();
                while (stackSize--) {
                    curr = oddST.top(); oddST.pop();
                    currVec.push_back(curr->val);
                    if (curr->left) evenST.push(curr->left);
                    if (curr->right) evenST.push(curr->right);
                }
            } else { // even
                stackSize = evenST.size();
                while (stackSize--) {
                    curr = evenST.top(); evenST.pop();
                    currVec.push_back(curr->val);
                    if (curr->right) oddST.push(curr->right);
                    if (curr->left) oddST.push(curr->left);
                }
            }
            
            ans.push_back(currVec);
            level++;
        }
        
        return ans;
    }
};