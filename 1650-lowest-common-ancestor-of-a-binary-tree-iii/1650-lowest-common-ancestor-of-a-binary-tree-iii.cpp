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
        
        Node* root = p;
        while (root->parent != NULL) root = root->parent;
        
        int pDep = getDepth(p), qDep = getDepth(q);
        
        while (p != root && pDep > qDep) {
            p = p->parent;
            --pDep;
        }
        while (q != root && pDep < qDep) {
            q = q->parent;
            --qDep;
        }
        
        if (p == root || q == root) return root;
        
        while (p && q && p != q) {
            p = p->parent, q = q->parent;
        }
        
        return p;
    }
};