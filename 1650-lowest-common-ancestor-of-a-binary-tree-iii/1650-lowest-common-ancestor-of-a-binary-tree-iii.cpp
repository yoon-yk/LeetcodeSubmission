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
    int getDepth(Node* node, Node* target) {
        if (node == NULL) return -1;
        if (node == target) return 0;
        
        if (node->left) {
            int leftD = getDepth(node->left, target);
            if (leftD > -1) return leftD+1;
        }
        if (node->right) {
            int rightD = getDepth(node->right, target);
            if (rightD > -1) return rightD+1;
        }
        return -1;
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        Node* root = p;
        while (root->parent != NULL) root = root->parent;
        
        int pDep = getDepth(root, p), qDep = getDepth(root, q);
        
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