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
        int n = lists.size();
        return divide(lists, 0, n-1);
    }
    
    ListNode* divide(vector<ListNode*>& ls, int start, int end) {
        
        if (start == end)
            return ls[start];
        while (start < end) {
            int mid = start + ((end-start) >> 1);
            ListNode* left = divide (ls, start, mid);
            ListNode* right = divide (ls, mid+1, end);
            return conquer(left, right);
        }
        return NULL;
    }
    
    ListNode* conquer(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curPtr = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curPtr->next = l1;
                l1 = l1->next; 
            } else {
                curPtr->next = l2;
                l2 = l2->next; 
            }
            curPtr = curPtr->next;
        } 
        if (l1) curPtr->next = l1;
        else curPtr->next = l2;
        
        return head->next;
    }
    
};