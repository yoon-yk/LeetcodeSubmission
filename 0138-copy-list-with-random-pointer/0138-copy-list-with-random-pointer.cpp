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
        unordered_map<Node*, Node*> mp;        
        return dupNode(head, mp);
    }
    
    Node* dupNode(Node* curNode, unordered_map<Node*, Node*>& mp) {
        
        if (!curNode) return NULL;
        
        if (mp.count(curNode))
            return mp[curNode];
        
        mp[curNode] = new Node(curNode->val);
        mp[curNode]->next = dupNode(curNode->next, mp);
        mp[curNode]->random = dupNode(curNode->random, mp);

        return mp[curNode];
    }
};