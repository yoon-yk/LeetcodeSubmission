/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;
        
        unordered_map<ListNode*, ListNode*> hashMap;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        while (ptrA) {
            ListNode* temp = ptrA;
            hashMap[temp] = temp;
            ptrA = ptrA->next;
        }
        // cout << "hh" << endl;
        // for (auto i:hashMap)
        //     cout << i.first << endl;
        
        while (headB) {
            if (hashMap.count(headB)) {
                ListNode *ptr1 = hashMap[headB];
                ListNode *ptr2 = headB;
                while (ptr1 && ptr2 && ptr1 == ptr2){
                    ptr1=ptr1->next;
                    ptr2=ptr2->next;
                }
                if (!ptr1 && !ptr2) return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    
    }
};