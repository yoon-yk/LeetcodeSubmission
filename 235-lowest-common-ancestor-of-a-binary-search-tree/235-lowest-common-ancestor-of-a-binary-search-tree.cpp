/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
  6
 2 8
[2,8] ==> 6 
[2,6] ==> 6
[6,8] ==> 6

    6
  2   8
 0 4 7 9
 [2,9] ==> 6
 [0,8] ==> 6
 [4,7] ==> 6

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        if (root->val == p->val || root->val == q->val) return root;
        if (p->val < root->val && q->val < root->val) {
            // 왼쪽 root 탐색하기 
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            // 오른쪽 root 탐색하기
            return lowestCommonAncestor(root->right, p, q);
        }
        //if (p->val < root->val && q->val < root->val) {
            return root;
    }
    
};