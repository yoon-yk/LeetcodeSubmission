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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dHead = new ListNode(200);
        ListNode *prev = dHead, *ptr = head;
        while (ptr) {
            if (prev->val != ptr->val) {
                prev->next = ptr;
                prev = ptr;
            }
            ptr = ptr->next; 
        }
        prev->next = NULL;
        return dHead->next;
    }
};