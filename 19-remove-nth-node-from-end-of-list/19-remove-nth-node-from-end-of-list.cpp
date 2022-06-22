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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || head->next == NULL) return NULL;
        
        ListNode *lead = head, *second = head, *prev = head;
        
        for (int i=0; i<n; i++)
            lead = lead->next;
        
        if (lead==NULL) { // 맨 첫번째 노드 제거하는 경우 
            head = head->next;
            return head;
        }
        
        while (lead!=NULL){
            lead=lead->next;
            prev=second;
            second=second->next;
        }
        
        prev->next = second->next;
        
        return head;
    }
};