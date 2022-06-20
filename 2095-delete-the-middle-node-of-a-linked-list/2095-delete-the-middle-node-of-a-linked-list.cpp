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
        if (head == NULL || head->next == NULL) return NULL; // 노드가 0개거나 1개인 경우 
        
        ListNode *lead = head, *del = head, *pre_del = head;
        while (lead!=NULL && lead->next!=NULL) {
            lead = lead->next->next;
            pre_del = del;
            del = del->next;
        }
        
        pre_del->next = del->next;
        delete del;
        
        return head;
        
    }
};