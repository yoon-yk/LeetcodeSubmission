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
    int pairSum(ListNode* head) {
        if (!head || !head->next) return 0;
        
        stack<int> nodeST;
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next) {
            nodeST.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast) slow = slow->next;
        
        int curr;
        int currSum = INT_MIN;
        while(!nodeST.empty() && slow) {
            curr = nodeST.top(); nodeST.pop();
            currSum = max(currSum, curr + slow->val);
            slow = slow->next;
        }
        
        return currSum;
    }
};