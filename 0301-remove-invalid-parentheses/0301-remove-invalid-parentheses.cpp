class Solution {
public:
    
    struct Node{
        int removal;
        int index;
        int valid;
        string str;
        
        Node(int _removal, int _index, int _valid, string _str) : 
        removal(_removal), index(_index), valid(_valid), str(_str) {};
    };
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        string cur;
        int minV = s.size()+1, idx, rem, valid;
        auto greater = [](const Node* a, const Node* b) {
            return (a->removal > b->removal);
        };
        
        unordered_map<string, unordered_set<int>> visited;
        priority_queue<Node*, vector<Node*>, decltype(greater)> pq(greater);
        pq.push(new Node(0, 0, 0, ""));
        visited[""].insert(0);

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            idx = cur->index, rem = cur->removal, valid = cur->valid;
            string & str = cur->str;            
            
            if (rem > minV) break;
            
            if (idx == s.size()) {
                if (valid != 0) continue;
                minV = rem;
                ans.push_back(str);
                continue;
            }
            
            if (s[idx] == '(') {
                if (!visited[str+s[idx]].count(rem)) {
                    pq.push(new Node(rem, idx+1, valid+1, str+s[idx])); // include
                    visited[str+s[idx]].insert(rem);
                }
                if (!visited[str].count(rem+1)) {
                    pq.push(new Node(rem+1, idx+1, valid, str)); // remove
                    visited[str].insert(rem+1);
                }

            } else if (s[idx] == ')') {
                if (valid > 0 && !visited[str+s[idx]].count(rem)) {
                    pq.push(new Node(rem, idx+1, valid-1, str+s[idx])); // include
                    visited[str+s[idx]].insert(rem);
                }
                if (!visited[str].count(rem+1)) {
                    pq.push(new Node(rem+1, idx+1, valid, str)); // remove
                    visited[str].insert(rem+1);
                }
            } else {
                if (!visited[str+s[idx]].count(rem)) {
                    pq.push(new Node(rem, idx+1, valid, str+s[idx])); // include
                    visited[str+s[idx]].insert(rem);
                }
            }
            
        }
        
        return ans;
    }
};