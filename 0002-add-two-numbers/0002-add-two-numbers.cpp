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
        ListNode *p1 = l1, *p2 = l2;
        ListNode *dHead = new ListNode();
        ListNode *sumList = dHead;
        
        bool carry = false;
        int sum;
        while (p1 || p2 || carry) {
            sum = carry;
            if (p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            
            if (p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            
            carry = (sum >= 10);
            sum %= 10;

            sumList->next = new ListNode(sum);
            sumList = sumList->next;
        }
        return dHead->next;
    }
};