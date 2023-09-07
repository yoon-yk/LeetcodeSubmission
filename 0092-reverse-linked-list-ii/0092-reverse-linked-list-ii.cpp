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
    ListNode* reverseList(ListNode* ntail, ListNode* nextNHead) {
        ListNode *f = ntail, *s = ntail, *t = NULL;
        while (f) {
            f = f->next;
            s->next = t;
            t = s;
            s = f;
        }
        ntail->next = nextNHead;
        return t;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* dHead = new ListNode(-1, head);
        ListNode* prevNTail, *nextNHead;
        ListNode* ntail = dHead, *nhead = dHead;

        for (int i=0; i<left; ++i) {
            prevNTail = ntail;
            ntail = ntail->next;
        }
        for (int i=0; i<right; ++i) {
            nhead = nhead->next;
        }
        nextNHead = nhead->next;
        nhead->next = NULL;
        
        prevNTail->next = reverseList(ntail, nextNHead);

        return dHead->next;
    }
};