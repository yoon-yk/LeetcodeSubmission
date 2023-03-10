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
    int computeDepth(TreeNode* node) {
        int d = 0;
        while (node->left) {
            node = node->left;
            ++d;
        }
        return d;
    }
    
    bool exists(int idx, int d, TreeNode* node) {
        int left = 0, right = (int)pow(2, d)-1;
        int pivot;
        
        for (int i=0; i<d; ++i) {
            pivot = left + ((right-left) >> 1);
            if (idx <= pivot) {
                node = node->left;
                right = pivot;
            } else {
                node = node->right;
                left = pivot + 1;
            }
        }
        return node;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int d = computeDepth(root);
        if (d == 0) return 1;
        
        int left = 1, right = (int)pow(2, d)-1;
        int pivot;
        while (left <= right) {
            pivot = left + ((right-left) >> 1);
            if (exists(pivot, d, root)) left = pivot + 1;
            else right = pivot - 1;
        }
        
        return (int)pow(2, d)-1 + left;
    }
};