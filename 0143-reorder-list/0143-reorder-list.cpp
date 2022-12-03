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
    
    ListNode* getMiddleNode(ListNode* head) {
        // find a middle node 
        ListNode* first = head, *second = head, 
        *third;
        while (first && first->next) {
            first = first->next->next;
            third = second;
            second = second->next;
        }
        ListNode* mid = second;
        if (third) third->next = NULL;
        
        return mid;
    }
    
    ListNode* getRListHead(ListNode* mid) {
        ListNode* first = mid, *second = mid, 
        *third=NULL;
         while (first) {
            first = first->next;
            second->next = third;
            third = second;
            second = first;
        }
        
        return third;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* pt1 = l1, *pt2 = l2;
        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;
        
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
        
        return newHead->next;
    }
    
    void reorderList(ListNode* head) {

        if (!head->next) return;
        
        ListNode* mid = getMiddleNode(head);
        ListNode* rlHead = getRListHead(mid);
        head = mergeLists(head, rlHead);

    }
};