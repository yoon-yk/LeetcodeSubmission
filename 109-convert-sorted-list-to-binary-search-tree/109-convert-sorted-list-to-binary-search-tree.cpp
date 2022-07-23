/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        // edge case : node # == 0 or 1 or even or odd
        
        // 1. fast-slow pointer
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        
        ListNode* fast=head, *slow=head, *prev = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        
        // 2. prev->next = null
        prev->next = NULL;
        
        // 3. left & right
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        // 4. return 
        return root;
    }
};