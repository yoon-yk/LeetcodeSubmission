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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // 둘다 null인 경우
        else if (!(p&&q)) return false;
        if (p && q && (p->val != q->val)) return false; // 갖고 있는 값 비교하기
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};