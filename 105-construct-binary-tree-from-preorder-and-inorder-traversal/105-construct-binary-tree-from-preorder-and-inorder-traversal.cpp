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
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right) {
        
        if (left > right) return NULL;
        
        int inorderIdx = left;
        while (inorder[inorderIdx] != preorder[rootIdx]) inorderIdx++;
        
        printf("left = %d, right = %d, rootIdx = %d, inorderIdx = %d\n", rootIdx, inorderIdx);

        TreeNode* header = new TreeNode(inorder[inorderIdx]);
        rootIdx ++;
        header->left = build(preorder, inorder, rootIdx, left, inorderIdx-1);
        header->right = build(preorder, inorder, rootIdx, inorderIdx+1, right);
        
        return header;
    }
};