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
    
    /*
    
            3
        9       20
    15    1   7     35
    
    preorder : [<3>, 9, 15, 1, 20, 7, 35]
    inorder : [15, 9, 1, <3>, 7, 20, 35]
    
    preorder - root -> left -> right
    inorder - left -> root -> right
    
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        int idx = 0;
        unordered_map<int, int> inMap;
        for (int i=0; i<preorder.size(); ++i) inMap[inorder[i]] = i;
        
        return getRoot(idx, 0, n-1, preorder, inMap);
        
    }
    
    TreeNode* getRoot(int& idx, int start, int end, vector<int>& preorder, unordered_map<int, int>& inMap) {
        
        if (start > end || idx == preorder.size()) return NULL;
        
        int rootVal = preorder[idx++];
        int rootIdx = inMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = getRoot(idx, start, rootIdx-1, preorder, inMap);
        root->right = getRoot(idx, rootIdx+1, end, preorder, inMap);
        
        return root;
    }
};