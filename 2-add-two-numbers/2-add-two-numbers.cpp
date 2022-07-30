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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        int currSum = 0, rest;
        bool prev_carry = false, curr_carry = false;
    
        ListNode *dummyHead = new ListNode();
        ListNode *ptr = dummyHead;
        
        while (l1 && l2) {
            currSum = l1->val + l2->val;
            prev_carry = curr_carry;
            if (prev_carry) currSum += 1;
            curr_carry = (currSum >= 10);
            rest = (curr_carry)? currSum %= 10 : currSum;
            
            ListNode *curr = new ListNode(rest);
            ptr->next = curr;
            ptr = ptr->next;
            
            l1 = l1->next; l2 = l2->next;
        }
        
        ListNode *restPtr;
        if (!l1) restPtr = l2;
        if (!l2) restPtr = l1;
                
        while (restPtr) {
            currSum = restPtr->val;
            prev_carry = curr_carry;
            if (prev_carry) currSum += 1;
            curr_carry = (currSum >= 10);
            rest = (curr_carry)? currSum %= 10 : currSum;
            
            ListNode *curr = new ListNode(rest);
            ptr->next = curr;
            ptr = ptr->next;    
            restPtr = restPtr->next;
        }
        
        if (curr_carry) {
            ptr->next = new ListNode(1);
        }
        
        return dummyHead->next;
    }
};