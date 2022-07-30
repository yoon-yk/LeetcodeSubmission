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
        
        // 1. hash map 만들기
        unordered_map<Node*, Node*> map;
        
        Node* dummyHead = new Node(0);
        Node* prev = dummyHead;
        
        // 2. head 타고 가면서 노드 새로 만들고, hash map에 넣기
        Node* origCurr = head, *copyCurr;
        while (origCurr) {
            copyCurr = new Node(origCurr->val);
            map[origCurr] = copyCurr;
            prev->next = copyCurr;
            prev = prev->next;
            origCurr = origCurr->next;
        }   
        
        // 3. head 다시 타고 가면서, map에서 copy linked list에서 해당하는 노드 불러오기 
        origCurr = head; 
        copyCurr = dummyHead->next;
        
        while (origCurr) {
            copyCurr->random = (map.count(origCurr->random))? map[origCurr->random] : NULL;
            origCurr = origCurr->next;
            copyCurr = copyCurr->next;
        } 
        
        return dummyHead->next;
        
    }
};