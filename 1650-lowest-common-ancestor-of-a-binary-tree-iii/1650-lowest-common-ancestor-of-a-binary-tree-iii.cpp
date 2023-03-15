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
    int getDepth(Node* root, Node* target) {
        
        queue<Node*> Q;
        Q.push(root);
        
        int dep = 0;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                if (cur == target) return dep;
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            ++dep;
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