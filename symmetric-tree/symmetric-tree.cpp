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
    void leftPostorder(TreeNode *root, vector<int>& left){
        if(!root){
            left.push_back(101);
            return;
        }
        leftPostorder(root->left, left);
        leftPostorder(root->right, left);
        left.push_back(root->val);
    }
    void rightPostorder(TreeNode *root, vector<int>& right){
        if(!root){
            right.push_back(101);
            return;
        }
        rightPostorder(root->right, right);
        rightPostorder(root->left, right);
        right.push_back(root->val);        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        vector<int> left;
        vector<int> right;
        leftPostorder(root->left, left);
        rightPostorder(root->right, right);
        return (left==right);
    }
};