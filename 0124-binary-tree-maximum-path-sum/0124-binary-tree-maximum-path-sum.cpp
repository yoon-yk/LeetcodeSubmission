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
    
    int maxPathSum(TreeNode* root) {
        
        int globalMaxSum = INT_MIN;
        pathSum(root, globalMaxSum);
        
        return globalMaxSum;
    }
    
    // root itself
    // left to root
    // right to root
    // 
    
    int pathSum(TreeNode* root, int& globalMaxSum) {

        if (!root) return 0;
        
        int rootVal = root->val;
        int lMaxSum = pathSum(root->left, globalMaxSum);
        int rMaxSum = pathSum(root->right, globalMaxSum);
        int includeRoot = lMaxSum + rMaxSum + rootVal;
        int ret = max(max(lMaxSum, rMaxSum) + rootVal, rootVal);
        
        globalMaxSum = max(globalMaxSum, max(includeRoot, ret));
        
        return ret;
    }
};