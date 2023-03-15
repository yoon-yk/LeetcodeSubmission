/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int getDepth(Node* target) {
        int dep = 0;
        while (target->parent != NULL) {
            target = target->parent;
            ++dep;
        }
        
        return dep;
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        int pDep = getDepth(p), qDep = getDepth(q);
        
        while (p->parent && pDep > qDep) {
            p = p->parent;
            --pDep;
        }
        while (q->parent && pDep < qDep) {
            q = q->parent;
            --qDep;
        }
        
        if (!p->parent) return p;
        else if (!q->parent) return q;
        
        while (p && q && p != q) {
            p = p->parent, q = q->parent;
        }
        
        return p;
    }
};