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
        /*  ts  f     
        <-1<-2  3->4->5 */
        ListNode *first = head, *second = head, *third = NULL;
        while (first) {
            first = first->next;
            second->next = third;
            third = second;
            second = first;
        }
        return third;
    }
};