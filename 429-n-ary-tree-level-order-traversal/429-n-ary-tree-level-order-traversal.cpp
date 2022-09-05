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
    vector<vector<int>> levelOrder(Node* root) {
        
        queue<Node*> q;
        vector<vector<int>> ans;
        if (root) q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> curLv;
            while (size--) {
                auto curNode = q.front(); q.pop();
                curLv.push_back(curNode->val);
                
                for(auto& ch : curNode->children)
                    q.push(ch);
            }
            ans.push_back(curLv);
        }
        
        return ans;
    }
};