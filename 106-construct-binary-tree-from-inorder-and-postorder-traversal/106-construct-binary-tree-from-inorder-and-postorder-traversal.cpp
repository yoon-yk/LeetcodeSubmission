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
        int postIdx = postorder.size();
        return builder(postIdx, 0, inorder.size()-1, inorder, postorder);
    }
    
    TreeNode* builder(int& postIdx, int inorderB, int inorderE, vector<int>& inorder, vector<int>& postorder) {
        
        int rootV = postorder[--postIdx];
        TreeNode* root = new TreeNode(rootV);        
        int inIdx = find(inorder.begin()+inorderB, inorder.begin()+inorderE, rootV) - inorder.begin();
        
        if (inIdx < inorderE) { // right child
            root->right = builder(postIdx, inIdx+1, inorderE, inorder, postorder);    
        }
        
        if (inIdx > inorderB) { // left child
            root->left = builder(postIdx, inorderB, inIdx-1, inorder, postorder);
        }
        
        return root;
    }
};