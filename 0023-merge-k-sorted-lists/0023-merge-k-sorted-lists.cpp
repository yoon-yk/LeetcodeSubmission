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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        while (lists.size() > 1) {
            ListNode* first = lists.back(); lists.pop_back();
            ListNode* second = lists.back(); lists.pop_back();
            lists.push_back(mergeTwoLists(first, second));
        }
        
        return lists.size() > 0 ? lists[0] : NULL;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cPtr = head;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cPtr->next = l1;
                l1 = l1->next;
            } else {
                cPtr->next = l2;
                l2 = l2->next;
            }
            cPtr = cPtr->next;
        }
        if (l1) cPtr->next = l1;
        else if (l2) cPtr->next = l2;
        
        return head->next;
    }
};