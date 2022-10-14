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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        
        ListNode* middle = dummyHead, *last = dummyHead,
        *prevMiddle = dummyHead;
        
        while (last && last->next){
            prevMiddle = middle;
            middle = middle->next;
            last = last->next->next;
        }
        
        if (last) {
            prevMiddle = prevMiddle->next;
            middle = middle->next;
        }
        
        /*
        
        0 1 2 3
            |   |
        0 1 2 3 4 
            |   |
        */
        prevMiddle->next = middle->next;
        return dummyHead->next;
    }
};