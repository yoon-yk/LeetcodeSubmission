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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> map;
        for (int i=0; i<inorder.size(); i++) map[inorder[i]] = i;
        
        int postIdx = postorder.size();
        return builder(postIdx, 0, inorder.size()-1, map, inorder, postorder);
    }
    
    TreeNode* builder(int& postIdx, int inorderB, int inorderE, unordered_map<int, int>& map, vector<int>& inorder, vector<int>& postorder) {
        
        int rootV = postorder[--postIdx];
        TreeNode* root = new TreeNode(rootV);        
        int inIdx = map[rootV];
        
        if (inIdx < inorderE) { // right child
            root->right = builder(postIdx, inIdx+1, inorderE, map, inorder, postorder);    
        }
        
        if (inIdx > inorderB) { // left child
            root->left = builder(postIdx, inorderB, inIdx-1, map, inorder, postorder);
        }
        
        return root;
    }
};