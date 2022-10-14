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
        *preMiddle = dummyHead;
        while (last && last->next){
            preMiddle = middle;
            middle = middle->next;
            last = last->next->next;
        }
        
        if (last) {
            preMiddle = middle;
            middle = middle->next;
        }
        /*
        
        0 1 2 3
            |   |
        0 1 2 3 4 
            |   |
        */
        preMiddle->next = middle->next;
        return dummyHead->next;
    }
};