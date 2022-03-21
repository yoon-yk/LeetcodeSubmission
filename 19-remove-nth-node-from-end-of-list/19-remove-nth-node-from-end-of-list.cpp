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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        
        int count = 0;
        ListNode* first = head;
        ListNode* second = head;
        ListNode* third = head;
        
        while (count < n) {
            first = first->next;
            count ++;
        }
        
        if (!first) { // size == linked list size
            second = head;
            head = head->next;
            delete second;
            return head;
        }
        
        while (first) {
            third = second;
            first = first->next;
            second = second->next;
        } 
                
        third->next = second->next;
        second->next = nullptr;
        
        
        return head;
    }
};