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
        
        ListNode* dHead = new ListNode();
        dHead->next = head;
        
        ListNode* first = head, *second = head, *third = NULL;
        ListNode* oHead = head, *pLast = dHead;
        ListNode* checkPtr = head;

        int checkCnt, cnt;
        
        while (true) {

            first = second = checkPtr = oHead;
            third = NULL;
            
            checkCnt = 0;
            while (checkPtr && checkCnt < k) {
                checkPtr = checkPtr->next;
                checkCnt ++;
            }
            if (checkCnt < k) {
                pLast->next = oHead;
                return dHead->next;
            }

            cnt = 0;
            while (first && cnt < k) {
                first = first->next;
                second->next = third;
                third = second;
                second = first;
                cnt ++;
            }

            pLast->next = third;
            pLast = oHead;
            oHead = second;
        }
    
    }
    
};