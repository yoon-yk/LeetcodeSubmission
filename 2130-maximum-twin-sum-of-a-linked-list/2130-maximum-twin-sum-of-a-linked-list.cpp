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
        
        stack<int> st;
        ListNode *fast = head, *middle = head, *prev = head;
        
        while (fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            middle = middle->next;
        }
                
        while (prev!= middle) {
            st.push(prev->val);
            prev = prev->next;
        }
        
        int curSum, maxN = INT_MIN;
        while (!st.empty() || middle!=NULL) {
            curSum = st.top() + middle->val;
            maxN = max(maxN, curSum);
            st.pop();
            middle = middle->next;
        }
        
        return maxN;
        
    }
};