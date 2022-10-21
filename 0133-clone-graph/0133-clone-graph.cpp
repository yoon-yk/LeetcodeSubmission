/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        
        if (node == NULL)
            return node;
        
        unordered_map<Node*, Node*> cloned;
        cloned[node] = new Node(node->val);
        
        queue<Node*> Q;
        Q.push(node);
        
        while (!Q.empty()) {
            auto curNode = Q.front(); Q.pop();
            
            for (auto& nei : curNode->neighbors) {
                if (!cloned.count(nei)) {
                    cloned[nei] = new Node(nei->val);
                    Q.push(nei);
                }
                cloned[curNode]->neighbors.push_back(cloned[nei]);
            }
        }
        
        return cloned[node];
    }
};