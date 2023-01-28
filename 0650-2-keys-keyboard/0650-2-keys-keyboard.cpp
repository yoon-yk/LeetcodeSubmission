class Solution {
public:
    int minSteps(int n) {
        
        // cur, hold
        // copy; hold = cur
        // paste; cur += hold
        
        int cur = 1, hold = 0, size, level = 0;
        
        queue<pair<int, int>> Q;
        unordered_map<int, unordered_set<int>> visited;
        Q.push({cur, hold});
        visited[cur].insert(hold);
        
        while (!Q.empty()) {    
            size = Q.size();
            while (size--) {
                auto [cur, hold] = Q.front(); Q.pop();
                if (cur == n) return level;
                
                // copy
                if (cur <= n && !visited[cur].count(cur)) {
                    Q.push({cur, cur});
                    visited[cur].insert(cur);
                }
                
                // paste   
                if (cur+hold <= n && !visited[cur+hold].count(hold)) {
                    Q.push({cur+hold, hold});
                    visited[cur+hold].insert(hold);
                }
            }
            ++level;
        }
        
        return -1;
    }
};