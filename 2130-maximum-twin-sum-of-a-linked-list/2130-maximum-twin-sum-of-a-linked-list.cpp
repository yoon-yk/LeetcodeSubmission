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
        
        // if (head == NULL) return 0;
        // if (head->next == NULL) return head->val;
        
        ListNode *fast = head, *middle = head, *prev = head;
        
        while (fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            middle = middle->next;
        }
        
        cout << middle->val << endl;
        
        stack<int> st;
        
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