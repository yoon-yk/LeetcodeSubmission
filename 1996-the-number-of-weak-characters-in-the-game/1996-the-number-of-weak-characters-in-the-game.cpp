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
        
        priority_queue<Node*, vector<Node*>, decltype(compare)> pq(compare);
        
        for (auto v : prop) {
            Node* newNode = new Node(v[0], v[1]);
            pq.push(newNode);
        }
        
        int cur, curAttack, prevMaxDefense = -1, curDefense = -1, ans = 0;
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (prevMaxDefense != -1 && cur->defense < prevMaxDefense) ans++;
            curDefense = max(curDefense, cur->defense);

            
            while (!pq.empty() && pq.top()->attack == cur->attack) {
                auto c = pq.top(); pq.pop();
                if (prevMaxDefense != -1 && c->defense < prevMaxDefense) ans++;
                curDefense = max(curDefense, c->defense);            
            }
            
            prevMaxDefense = max(prevMaxDefense, curDefense);
        }
        
        return ans;
    }
};