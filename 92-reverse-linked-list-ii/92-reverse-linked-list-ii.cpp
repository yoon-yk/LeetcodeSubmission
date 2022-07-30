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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return NULL;
        
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        
        ListNode* ptr = head, *prev = dummyHead, *rest = NULL, *start = NULL;
        
        int cnt = 1;
        while (ptr && cnt < left) {
            prev = ptr;
            ptr = ptr->next;
            cnt ++;
        }
        start = ptr; // Save the starting pointer to modify the next link at line 32.

        // Reverse
        
        ListNode* lead = ptr, *curr, *tail;        
        while (lead && cnt <= right) {
            tail = curr;
            curr = lead;
            lead = lead->next;
            if (cnt == right) rest = curr->next;
            curr->next = tail;
            cnt++;
        }
        
        prev->next = curr;
        start->next = rest; // Link the rest nodes;

        return dummyHead->next;
    }

};