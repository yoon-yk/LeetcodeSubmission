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
        unordered_map<Node*, int> origNodeMap;
        unordered_map<int, Node*> copyIdxMap;
        
        Node* dummyHead = new Node(0);
        Node* prev = dummyHead;
        
        // 2. head 타고 가면서 노드 새로 만들고, hash map에 넣기
        Node* origCurr = head, *copyCurr;
        int idx = 0;
        while (origCurr) {
            copyCurr = new Node(origCurr->val);
            origNodeMap[origCurr] = idx;
            copyIdxMap[idx] = copyCurr;
            
            prev->next = copyCurr;
            prev = copyCurr;
            origCurr = origCurr->next;
            idx++;
        }
        prev->next = NULL;
   
        
        // 3. head 다시 타고 가면서, orgNodeMap에서 idx 찾아주고, copyIdxMap에서 해당 Idx에 해당하는 노드 불러오기 
        origCurr = head; 
        copyCurr = dummyHead->next;
        
        while (origCurr) {
            copyCurr->random = (origNodeMap.count(origCurr->random))? copyIdxMap[origNodeMap[origCurr->random]] : NULL;
            origCurr = origCurr->next;
            copyCurr = copyCurr->next;
        } 
        
        return dummyHead->next;
        
    }
};