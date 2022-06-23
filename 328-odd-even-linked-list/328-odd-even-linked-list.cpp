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
    ListNode* oddEvenList(ListNode* head) {
        
        if (head==NULL || head->next==NULL) return head;
        
        ListNode* ptr = head;
        ListNode* oddhead = NULL, *oddptr = NULL;
        ListNode* evenhead = NULL, *evenptr = NULL;
        
        int cnt = 0;
        while (ptr){
            if (cnt%2 == 1) { // odd num
                if (oddhead == NULL) {
                    oddhead = ptr;
                    oddptr = ptr;
                }
                else {
                    oddptr->next = ptr;
                    oddptr = oddptr->next;
                }
            } else { // even num
                if (evenhead == NULL) {
                    evenhead = ptr;
                    evenptr = ptr;
                }
                else {
                    evenptr->next = ptr;
                    evenptr = evenptr->next;
                }
            }
            ptr = ptr->next;
            cnt++;
        }
        
        evenptr->next = oddhead;
        oddptr->next = NULL;
        
        return evenhead;
    }
};