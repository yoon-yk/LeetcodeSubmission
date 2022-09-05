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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int maxLen = 0;
        dfs(root, INT_MAX, 0, maxLen);
        
        return maxLen;
    }
    
    // dfs
    
    void dfs(TreeNode* root, int prev, int curLen, int& maxLen) {
        // pass previous value, current seq len, (reference)max seq len, 
        
        // if current node value is consecutive, increase curr seq len and compare the max seq len + 
        if (maxLen!= 0 && root->val == prev+1) 
            curLen++;
        else 
        // if current node value is not consecutive, reset cur seq len to 1 and traverse ~ 
            curLen = 1;
        
        maxLen = max(maxLen, curLen);

        // update prev value
        prev = root->val;
        
        // traverse child node
        if (root->left) dfs(root->left, prev, curLen, maxLen);
        if (root->right) dfs(root->right, prev, curLen, maxLen);
    }

    
    
};