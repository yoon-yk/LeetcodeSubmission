/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> rootQ;
        rootQ.push(root);
        
        while (rootQ.size()) {
            
            Node* currRoot = rootQ.front(); rootQ.pop();
            Node* prevN = NULL;
                
            for (Node* curr = currRoot; curr; curr = curr->next) {
                                                
                if (curr->left) {
                    if (prevN) prevN->next = curr->left;
                    else rootQ.push(curr->left);
                    prevN = curr->left;
                }
                
                if (curr->right) {
                    if (prevN) prevN->next = curr->right;
                    else rootQ.push(curr->right);
                    prevN = curr->right;
                }
                
            }
        }
        
        return root;
    }
};