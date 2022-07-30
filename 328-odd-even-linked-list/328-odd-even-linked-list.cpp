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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        
        // 1. create an even Head 
        ListNode* evenHead = new ListNode();
        ListNode* evenPtr = evenHead;
        
        // 2. iterate over the list and take out the even indiced node and link to the new list
        ListNode *ptr = head, *prev = head;
        bool isEven = false;
        
        while (ptr) {
            if (isEven) {
                prev->next = ptr->next;
                evenPtr->next = ptr;
                ptr = ptr->next;

                evenPtr = evenPtr->next;
                evenPtr->next = NULL;
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
            
            isEven = !isEven;
        }

        
        // 3. link the odd head to the last node of the list when the iteration is over.
        prev->next = evenHead->next;
        
        // return NULL;
        return head;
    }
    
};