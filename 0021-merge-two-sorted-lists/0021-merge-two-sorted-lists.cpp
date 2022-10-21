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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* newListPtr = dummyHead;
        
        ListNode* ptr1 = list1, *ptr2 = list2;
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                newListPtr->next = ptr1;
                ptr1 = ptr1->next;
                newListPtr->next->next = NULL;
            } else {
                newListPtr->next = ptr2;
                ptr2 = ptr2->next;
                newListPtr->next->next = NULL;
            }
            newListPtr = newListPtr->next;
        }
        if (ptr1)
            newListPtr->next = ptr1;
        else if (ptr2)
            newListPtr->next = ptr2;
        
        return dummyHead->next;
    }
};