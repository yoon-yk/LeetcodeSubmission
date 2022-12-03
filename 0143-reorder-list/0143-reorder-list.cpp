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
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* ptr = head, *temp;
        
        int idx=0;
        for(; ptr; idx++) {
            mp[idx] = ptr;
            temp = ptr->next;
            ptr->next = NULL;
            ptr = temp;
        }
        
        ListNode* dHead = new ListNode();
        ptr = dHead;
        for (int i=0; i< (idx >> 1); i++) {
            ptr->next = mp[i];
            ptr->next->next = mp[idx-1-i];
            ptr = ptr->next->next;
        }
        
        if (idx % 2) 
            ptr->next = mp[idx>>1];
        
    }
};