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
        unordered_map<Node*, Node*> parent;
        
        for (auto& nd : tree)
            for (auto& ch : nd->children)
                parent[ch] = nd;

        
        Node* cur = tree[0];
        while (parent.count(cur))
            cur = parent[cur];
        
        return cur;
    }
};