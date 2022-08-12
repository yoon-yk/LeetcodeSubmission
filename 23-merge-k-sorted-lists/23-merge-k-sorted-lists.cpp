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
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (ListNode* cur : lists) {
            while (cur){
                pq.push(cur->val);
                cur = cur->next;
            }

        }
        
        int curN;
        ListNode* head = new ListNode();
        ListNode* curP = head;
        while (!pq.empty()) {
            curN = pq.top(); 
            pq.pop();
            curP->next = new ListNode(curN);
            curP = curP->next;
        }
        
        return head->next;
    }
};