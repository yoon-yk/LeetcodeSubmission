/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node*, Node*> par;
        for (auto & n : tree) {
            for (auto child : n->children)
                par[child] = n;
        }
        
        for (auto & n : tree) {
            if (!par.count(n)) return n;
        }
        
        return NULL;
    }
};