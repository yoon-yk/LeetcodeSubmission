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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* lastNode;
        head = reverseNodes(head, k);
        return head;
    }
    
    ListNode* reverseNodes(ListNode* head, int k) {
        
        ListNode* first = head, *second = head, *third = NULL;
        ListNode* oHead = head;
        
        ListNode* checkPtr = head;
        int checkCnt = 0;
        while (checkPtr && checkCnt < k) {
            checkPtr = checkPtr->next;
            ++ checkCnt;
        }
        if (checkCnt < k) return head;
        
        int cnt = 0;
        while (first && cnt < k) {
            first = first->next;
            second->next = third;
            third = second;
            second = first;
            cnt ++;
        }
        
        if (second) oHead->next = reverseNodes(second, k);
        return third;
    }
};