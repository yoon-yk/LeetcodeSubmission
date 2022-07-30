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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return NULL;
        
        int cnt = 1;
        
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        
        ListNode* ptr = head, *prev = dummyHead, *rest = NULL, *start = NULL;
        
        while (ptr && cnt < left) {
            prev = ptr;
            ptr = ptr->next;
            cnt ++;
        }
        start = ptr; // Save the starting pointer to modify the next link at line 32.

        prev->next = helper(ptr, rest, cnt, right);
        start->next = rest; // Link the rest nodes;

        return dummyHead->next;
    }
    
    
    ListNode* helper(ListNode* ptr, ListNode*& rest, int &cnt, int right) {
        if (!ptr) return NULL;
        if (cnt == right) {
            rest = ptr->next;
            return ptr;
        }
        cnt ++;
        ListNode* node = helper(ptr->next, rest, cnt, right);
        ptr->next->next = ptr;
        ptr->next = NULL;
        return node;
    }
};