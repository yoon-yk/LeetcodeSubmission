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
    unordered_map<Node*, Node*> hashM;
    
    Node* cloneGraph(Node* node) {
        
        if (!node) return node;
        
        if (hashM.count(node))
            return hashM[node];
        
        Node* curNode = new Node(node->val);
        hashM[node] = curNode;
        
        for (auto & nei : node->neighbors) {
            curNode->neighbors.push_back(cloneGraph(nei));
        }
        
        return curNode;
    }
};