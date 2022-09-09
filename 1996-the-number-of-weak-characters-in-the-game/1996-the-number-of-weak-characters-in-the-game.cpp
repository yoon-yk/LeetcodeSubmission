class Solution {
public:
    struct Node {
        int attack;
        int defense;
        Node(int _attack, int _defense) : attack(_attack), defense(_defense) {};
    };
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {

        auto compare = [](Node* a, Node* b) {
            return a->attack < b->attack;
        };
        
        auto min_compare = [](Node* a, Node* b) {
            return a->defense > b->defense;
        };
        
        priority_queue<Node*, vector<Node*>, decltype(compare)> pq(compare);
        queue<Node*> subq;
        
        for (auto v : prop) {
            Node* newNode = new Node(v[0], v[1]);
            pq.push(newNode);
        }
        
        int cur, curAttack, prevMaxDefense = -1, curDefense = -1, ans = 0;
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            subq.push(cur);
            
            while (!pq.empty() && pq.top()->attack == cur->attack) {
                auto dep = pq.top(); pq.pop();
                subq.push(dep);
            }
            
            while (!subq.empty()) {
                auto c = subq.front(); subq.pop();
                if (prevMaxDefense != -1 && c->defense < prevMaxDefense) ans++;
                curDefense = max(curDefense, c->defense);
            }
            
            prevMaxDefense = max(prevMaxDefense, curDefense);
        }
        
        return ans;
    }
};