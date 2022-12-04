/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        bool cycle = false;
        while (first && first->next) {
            second = second->next;
            first = first->next->next;
            
            if (first == second) {
                cycle = true;
                break;
            }
        } 
        if (!cycle) return NULL;
        
        second = head;
        while (first != second) {
            second = second->next;
            first = first->next;
        }
        
        return first;
    }
};