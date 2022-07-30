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
    Node* copyRandomList(Node* head) {
        
        Node* curr = head, *next;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (curr) {
            next = curr->next;

            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = next;

            curr = next;
        }

        // Second round: assign random pointers for the copy nodes.
        curr = head;
        while (curr) {
            if (curr->random) 
                curr->next->random = curr->random->next; /* copied node's random = copied random node */
            curr = curr->next->next;
        }

        // Third round: restore the original list, and extract the copy list.
        curr = head;
        Node* dummyHead = new Node(0);
        Node* copy, *copyIter = dummyHead;

        while (curr) {
            next = curr->next->next;

            // extract the copy
            copy = curr->next;
            copyIter->next = copy;
            copyIter = copy;

            // restore the original list
            curr->next = next;

            curr = next;
        }

        return dummyHead->next;
    }
};