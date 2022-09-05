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
        
        int valueSum = 0;
        for (auto& nd : tree) {
            valueSum += nd->val;
            for (auto& ch : nd->children)
                valueSum -= ch->val;
        }
        
        for (auto& nd : tree) 
            if (nd->val == valueSum)
                return nd;
        
        return NULL;
    }
};