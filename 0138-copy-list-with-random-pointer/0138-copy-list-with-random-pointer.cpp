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
        if (!head) return head;
        
        Node* curPtr = head;        
        while (curPtr) {
            Node* nNode = new Node(curPtr->val);
            nNode->next = curPtr->next;
            curPtr->next = nNode;
            curPtr = nNode->next;
        }

        curPtr = head;
        while (curPtr) {
            curPtr->next->random = 
                (curPtr->random) ? curPtr->random->next : NULL;
            curPtr = curPtr->next->next;
        }
        
        // 7 7 13 13 11 11 10 10 1 1 
        Node* nHead = head->next, *oPtr, *cPtr;
        oPtr = head, cPtr = head->next;
        while (oPtr) {
            cPtr = oPtr->next;
            oPtr->next = cPtr->next;
            if (cPtr->next) cPtr->next = cPtr->next->next;
            oPtr = oPtr->next;
        }
        
        // Node* pPtr = nHead;
        // while (pPtr) {
        //     int v = pPtr->val;
        //     int nv = (pPtr->next) ? pPtr->next->val : 0;
        //     int rv = (pPtr->random) ? pPtr->random->val : 0;
        //     cout << v << "/" << nv << "/" << rv << endl;
        //     pPtr = pPtr->next;
        // }
        // cout << endl;
        
        return nHead;
    }
};