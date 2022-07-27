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
        if (!root) return NULL;
        
        queue<Node*> rootQ;
        rootQ.push(root);
        
        while (!rootQ.empty()) {
            
            Node* prevN = NULL;
            int curQsize = rootQ.size();
            
            while (curQsize--){
                Node* curr = rootQ.front(); rootQ.pop();
                
                Node* left = curr->left, *right = curr->right;
                if (left) {
                    if (prevN) prevN->next = left;
                    prevN = left;
                    rootQ.push(left);
                }
                
                if (right) {
                    if (prevN) prevN->next = right;
                    prevN = right;
                    rootQ.push(right);
                }                
            }
                
        }
        
        return root;
    }
};