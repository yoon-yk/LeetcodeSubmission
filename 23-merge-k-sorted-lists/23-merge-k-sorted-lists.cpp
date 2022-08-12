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
        
        auto compare = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        
        ListNode* tmp;
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        for (ListNode* cur : lists) {
            while (cur){
                tmp = cur->next;
                cur->next = NULL;
                pq.push(cur);
                cur = tmp;
            }

        }
        
        ListNode* head = new ListNode();
        ListNode* curP = head;
        while (!pq.empty()) {
            curP->next = pq.top();
            pq.pop();
            curP = curP->next;
        }
        
        return head->next;
    }
};