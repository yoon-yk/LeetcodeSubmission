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
    unordered_map<Node*, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        
        if (node == NULL)
            return node;
        
        if (visited.count(node))
            return visited[node];
        
        Node * cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        
        for (Node* nei : node->neighbors)
            cloneNode->neighbors.push_back(cloneGraph(nei));
        return cloneNode;
    }
};