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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIdx = -1;
        return helper(preorderIdx, 0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* helper(int& preorderIdx, int inorderBeginIdx, int inorderEndIdx, vector<int>& preorder, vector<int>& inorder) {
                
        preorderIdx += 1;
        int rootVal = preorder[preorderIdx];
        TreeNode* root = new TreeNode(rootVal, nullptr, nullptr);
        int inorderRootIdx = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

        if (inorderRootIdx > inorderBeginIdx) { // left child exists 
            root->left = helper(preorderIdx, inorderBeginIdx, inorderRootIdx-1, preorder, inorder);
        }
        
        if (inorderRootIdx < inorderEndIdx) {
            root->right = helper(preorderIdx, inorderRootIdx+1, inorderEndIdx, preorder, inorder);
        }
        
        return root;
    }
};