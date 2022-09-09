class Solution {
public:
    struct Node {
        int attack;
        int defense;
        Node(int _attack, int _defense) : attack(_attack), defense(_defense) {};
    };
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {

        auto compare = [](Node* a, Node* b) {
          if (a->attack == b->attack)
               return a->defense > b->defense;
          return a->attack < b->attack;
        };
        
        priority_queue<Node*, vector<Node*>, decltype(compare)> pq(compare);
        
        for (auto v : prop)
            pq.push(new Node(v[0], v[1]));
        
        int maxDefense = -1, ans = 0;
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (cur->defense < maxDefense) ans++;
            maxDefense = max(maxDefense, cur->defense);
        }
        
        return ans;
    }
};