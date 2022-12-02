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
        
        auto compare = [](const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for (auto & list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode* retHead = new ListNode();
        ListNode* retPtr = retHead;
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (cur->next) pq.push(cur->next);
            cur->next = NULL;
            retPtr->next = cur;
            retPtr = retPtr->next;
        }
        
        return retHead->next;
    }
};