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


/*
   3(3)
1(1)   4(4)
 2(2)
 

      5
   1     7
  0 3   6 8
     4
   
inorder !!! left, root, right

==>>> inorder in iterative way????? stack!!!

[k == n]

*/


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        if (!root) return 0;
            
        int cnt = 0, ret = -1;
        TreeNode *ptr = root, *head = root;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *cur = root->left;
        
        
        while(cur || !s.empty()) {
            
            while (cur) {
               s.push(cur);
               cur=cur->left;
            }
            
            cur = s.top();
            s.pop();
            // printf("%d\n", cur->val);
            
            if (++cnt == k) {
                ret = cur->val;
                break;
            }
            cur = cur->right;
        }
        
        return ret;
    }

};