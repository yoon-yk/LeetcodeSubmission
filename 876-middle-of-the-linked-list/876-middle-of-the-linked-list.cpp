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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* first = head;
        ListNode* second = head;
        
        while (second!= NULL && second->next != NULL) { // 조건 !!!!!!!!! 
            second = second->next->next;
            first = first->next;
        }
        
        return first;
    }
};