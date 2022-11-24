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
    TreeNode* sR;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        sR = subRoot;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur->val == subRoot->val) {
                if (isSameTree(cur, subRoot))
                    return true;
            }
            if (cur->left) Q.push(cur->left);
            if (cur->right) Q.push(cur->right);
        }
        return false;
    }
    
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        else if (!a || !b) return false;
        else if (a->val != b->val) return false;
        
        bool isLeftSame = isSameTree(a->left, b->left);
        bool isRightSame = isSameTree(a->right, b->right);
        
        if (!sR && a->val == sR->val) {
            TreeNode * temp = sR;
            if (isSameTree(a, temp))
                return true;
        }
        
        return isLeftSame && isRightSame;
    }
    
};