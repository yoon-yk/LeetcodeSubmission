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
        
        int currSum = 0, digit, l1val, l2val;
        bool prev_carry = false, curr_carry = false;
    
        ListNode *dummyHead = new ListNode();
        ListNode *ptr = dummyHead;
        
        while (l1 || l2 || curr_carry) { 
            prev_carry = curr_carry;
            
            l1val = (l1)? l1->val : 0;
            l2val = (l2)? l2->val : 0;
            
            currSum = l1val + l2val + prev_carry;
            curr_carry = (currSum >= 10);
            digit = currSum %= 10;
            
            ListNode *curr = new ListNode(digit);
            
            ptr->next = curr;
            ptr = ptr->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        
        return dummyHead->next;
    }
};