class Solution {
public:

    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        
        priority_queue<vector<int>> pq;
        
        for (auto v : prop) {
            pq.push({v[0], v[1]});
        }
        
        int cur, curAttack, prevMaxDefense = -1, currMaxDefense = -1, ans = 0;
        
        while (!pq.empty()) {
            auto cur = pq.top(); 
            currMaxDefense = cur[1];
            
            while (!pq.empty() && pq.top()[0] == cur[0]) {
                auto c = pq.top(); pq.pop();
                if (prevMaxDefense != -1 && c[1] < prevMaxDefense) ans++;
            }
            
            prevMaxDefense = max(prevMaxDefense, currMaxDefense);
        }
        
        return ans;
    }
};