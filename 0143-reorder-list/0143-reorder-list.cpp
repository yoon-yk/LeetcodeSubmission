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
    ListNode* getLastNode(ListNode* head) {
                
        ListNode* ptr = head, *ePtr = NULL;
        while (ptr && ptr->next) {
            ePtr = ptr;
            ptr = ptr->next;
        }
        if (ePtr) ePtr->next = NULL;
        return ptr;
    }
    
    void reorderList(ListNode* head) {
       
        ListNode* curFirst = head;
        ListNode* globalPtr = curFirst;
        ListNode* curLast = getLastNode(curFirst);
        
        while (curFirst != curLast) {
            curLast->next = curFirst->next;
            curFirst->next = curLast;
            curFirst = curFirst->next->next;
            curLast = getLastNode(curFirst);
        }
        
        if (curFirst) curFirst->next = NULL;
        
    }
};