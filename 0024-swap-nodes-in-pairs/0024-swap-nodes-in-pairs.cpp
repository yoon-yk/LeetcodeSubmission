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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dHead = new ListNode();
        dHead->next = head;
        ListNode* ptr = dHead->next, *prev = dHead;
        
        while (ptr && ptr->next) {
            ListNode* first = ptr;
            ListNode* second = ptr->next;
            ListNode* rest = second->next;
            
            first->next = rest;
            second->next = first;
            prev->next = second;
            prev = first;
            ptr = rest;
        }
        
        return dHead->next;
    }
};