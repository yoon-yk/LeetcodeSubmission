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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head, *slow = head, *tail = NULL, *body = NULL;
        
        
        while (fast && fast->next) {
            fast = fast->next->next;
            tail = body;
            body = slow;
            slow = slow->next;
            body->next = tail;
        }
        
        if (fast) slow = slow->next;
        
        while (body && slow) {
            if (slow->val != body->val) return false;
            body = body->next;
            slow = slow->next;
        }
        
        return true;
    }
};