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
    
    // edge case : even number, odd number, no node, one node
    
    bool isPalindrome(ListNode* head) {
        
        
        stack<int> st;
        
        // 1. find middle + push nodes into stack
        ListNode *lead = head, *middle = head;
        while (lead!=NULL && lead->next!=NULL) {
            st.push(middle->val);
            lead = lead->next->next;
            middle = middle->next;
        }
        
        // 길이가 odd인 경우 lead는 마지막 노드에 가있음 !!! 
        if (lead!=NULL) middle=middle->next;
        
        // 2. middle->end + pop from stack with comparison
        // 에러 핸들링 stack이 먼저 비는 경우, end에 먼저 닿는 경우! -> false 
        int stTop;
        while (!st.empty() || middle!=NULL){
            stTop = st.top();
            cout << stTop << "&&" << middle->val << endl;
            if (stTop!= middle->val) return false;
            st.pop();
            middle = middle->next;
        }
        
        if (!st.empty() || middle!=NULL) return false;
        return true;

    }
};