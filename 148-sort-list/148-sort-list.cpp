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
    ListNode* sortList(ListNode* head) {
        
        if(!head||!head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        
        ListNode* lptr = left, *rptr = right;
        ListNode* dhead = NULL, *dptr = dhead;
        
        while (lptr && rptr){
            if (lptr->val < rptr->val){
                if (dhead == NULL) {
                    dhead = dptr = lptr;
                } else {
                    dptr->next = lptr;
                    dptr = dptr->next;
                }
                lptr = lptr->next;
            }
            else {
                if (dhead == NULL) {
                    dhead = dptr = rptr;
                } else {
                    dptr->next = rptr;
                    dptr = dptr->next;
                }
                rptr = rptr->next;
            }
        }
        
        if(lptr)
            dptr->next = lptr;
        else if (rptr)
            dptr->next = rptr;
        
        return dhead;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* mid = head;
        ListNode* midpv = head; 
        while(head&&head->next){
            head = head->next->next;
            midpv = mid;
            mid = mid->next;
        }
        midpv->next = NULL;
        return mid;
    }
    
    
};