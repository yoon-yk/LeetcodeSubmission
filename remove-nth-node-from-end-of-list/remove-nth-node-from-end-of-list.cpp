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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode *end = head;
        ListNode *delPrev = head;
        ListNode *delNode;
        int cnt = 0;
        
        // set *end = *delPrev + n
        for(int i=0; i<n; i++){
            end = end->next;
        }
        
        // if end reached to the end
        // it means that n is larger than the whole length
        if(end==NULL){
            delNode = head;
            head = head -> next;
            delete delNode;
            return head;
        }
        
        while(end->next!=NULL){
            end = end->next;
            delPrev = delPrev->next;
        }
 
        delNode = delPrev->next; 
        delPrev->next= delNode->next;
        delete delNode;
        return head;
    }
};