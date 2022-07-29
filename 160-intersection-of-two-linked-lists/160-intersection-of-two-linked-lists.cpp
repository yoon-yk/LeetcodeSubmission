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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;
                
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while (ptrA!=ptrB) {
            ptrA = (ptrA)? ptrA->next : headB;
            ptrB = (ptrB)? ptrB->next : headA;
        }
        
        return ptrA;
    
    }
};