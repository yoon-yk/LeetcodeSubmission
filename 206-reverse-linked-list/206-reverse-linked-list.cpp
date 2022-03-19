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
    ListNode* reverseList(ListNode* head) {
        ListNode *first = head, *mid = head, *last = nullptr;
        while (first) {
            head = first;
            first = first->next;
            mid->next = last;
            last = mid;
            mid = first;
        }
        return head;
    }
};