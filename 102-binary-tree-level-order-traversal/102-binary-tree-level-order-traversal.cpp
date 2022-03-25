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
        
        vector<vector<int>> res;
        int level = 0; 
        map <int, vector<int>> hashT;
        if (root == NULL) return res;
        
        traversal(root, hashT, level);
        for (auto i:hashT) res.push_back(i.second);
        return res;
    }
    
    void traversal(TreeNode* root, map <int, vector<int>> &hashT, int level) {
        if (root == NULL) return;
        hashT[level].push_back(root->val);
        traversal(root->left, hashT, level+1);
        traversal(root->right, hashT, level+1);
    }
};