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
        if (lists.empty()) return nullptr;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Insert every node into minHeap 
        for (auto head : lists){
            while(head){
                minHeap.push(head->val);
                head=head->next;
            }
        }
        
        // Pop every node in increasing order
        ListNode *head = new ListNode();
        ListNode *cur = head;
        while(!minHeap.empty()){
            cur->next = new ListNode(minHeap.top());
            minHeap.pop();
            cur = cur->next;
        }
        
        return head->next;
    }
};