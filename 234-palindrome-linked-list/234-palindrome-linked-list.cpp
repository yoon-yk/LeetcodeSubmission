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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        stack<ListNode*> stackNode;
        
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            stackNode.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If odd  [a - b] - <c> - b - a
        if (fast) {
            slow = slow->next;
        } 
        
        ListNode* curr;
        while(!stackNode.empty() && slow) {
            curr = stackNode.top(); stackNode.pop();
            if (curr->val != slow->val) break;
            slow = slow->next;
        }
        
        return (stackNode.empty() && !slow);
    }
};