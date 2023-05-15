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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* first = head, *second = head;
        for (int i=0; i<k && first; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        
        ListNode* fromHead = head; 
        for (int i=0; i<k-1 && fromHead; ++i) {
            fromHead = fromHead->next;
        }
        
        swap(second->val, fromHead->val);
        
        return head;
    }
};