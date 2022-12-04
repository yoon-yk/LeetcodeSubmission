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
    ListNode* findMiddle(ListNode* head) {
        ListNode* dHead = new ListNode();
        dHead->next = head;
        ListNode* first = dHead, *second = dHead;
        while (first && first->next) {
            first = first->next->next;
            second = second->next;
        }
        ListNode* mid = second->next;
        second->next = NULL;
        return mid;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *first = head, *second = head, *third=NULL;
        while (first) {
            first = first->next;
            second->next = third;
            third = second;
            second = first;
        }
        return third;
    }
    
    ListNode* mergeLists(ListNode* head, ListNode* sHead) {
        ListNode* dHead = new ListNode();
        ListNode* cur = dHead;
        
        ListNode* pt1 = head, *pt2 = sHead;
        while (pt1 || pt2) {
            if (pt1) {
                cur->next = pt1;
                pt1 = pt1->next;
                cur = cur->next;
            }
            
            if (pt2) {
                cur->next = pt2;
                pt2 = pt2->next;
                cur = cur->next;
            }
        }
        
        return dHead->next;
    }
    
    void reorderList(ListNode* head) {
        // find middle
        ListNode* mid = findMiddle(head);
        // reverse the second middle list
        ListNode* sHead = reverseList(mid);
        // merge two list
        head = mergeLists(head, sHead);
    }
};