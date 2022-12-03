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
        return divide(lists, 0, lists.size()-1);
    }
    
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l==r)
            return lists[l];
        
        if (l < r) {
            int mid = l + ((r-l) >> 1);
            ListNode* left = divide(lists, l, mid);
            ListNode* right = divide(lists, mid+1, r);
            return mergeTwoLists(left, right);
        }
        
        return NULL;
    }
    
    /*
    ㅇ ㅇ ㅇ ㅇㅡㅇ
    ㅇ ㅇ ㅇㅡㅇ
    ㅇ ㅇㅡㅇ
    ㅇㅡㅇ 
    ㅇ     
    (N-1)번 반복 * K
    
    */
    ListNode* mergeTwoLists(ListNode*& l1, ListNode*& l2) {
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