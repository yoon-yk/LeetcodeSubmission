/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void duplicateNodes(Node* head) {
        Node* ptr = head;
        while (ptr) {
            Node* dup = new Node(ptr->val);
            dup->next = ptr->next;
            ptr->next = dup;
            ptr = dup->next;
        }
    }
    
    void adjustNextPtr(Node* head, Node* dHead) {
        Node* oPtr = head, *dPtr = dHead;
        while (oPtr && dPtr) {
            oPtr->next = dPtr->next;
            dPtr->next = (dPtr->next) ? dPtr->next->next : NULL;
            oPtr = oPtr->next;
            dPtr = dPtr->next;
        }
    }
    
    void adjustRandPtr(Node* head) {
        Node* ptr = head, *dPtr;
        while (ptr && ptr->next) {
            dPtr = ptr->next;
            if (ptr->random) dPtr->random = ptr->random->next;
            ptr = ptr->next->next;
        }
    }
    
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        // 각 node 에 next에 dup 만들어주기 
        duplicateNodes(head);
        adjustRandPtr(head);
        Node* orig = head, *dup = head->next;
        adjustNextPtr(orig, dup);

        return dup;
    }
};