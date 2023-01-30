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
        
        unordered_map<Node*, Node*> dup;
        
        // next
        Node* ptr = head;
        if (ptr) dup[ptr] = new Node(ptr->val);
        
        while (ptr && ptr->next) {
            dup[ptr->next] = new Node(ptr->next->val);
            dup[ptr]->next = dup[ptr->next];
            ptr = ptr->next;
        }
        
        ptr = head;
        while (ptr) {
            if (ptr->random) {
               dup[ptr]->random = dup[ptr->random]; 
            } 
            ptr = ptr->next;
        }
        
        // random
        return dup[head];
    }
};