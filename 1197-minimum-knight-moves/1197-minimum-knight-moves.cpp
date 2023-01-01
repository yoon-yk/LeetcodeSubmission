class Solution {
public:
    int base = 300;
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        x += base, y += base;
        vector<pair<int, int>> dir = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(605, vector<bool>(605, false));
        
        int steps = 0;
        Q.push({base, base});
        visited[base][base] = true;
        
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto [r, c] = Q.front(); Q.pop();
                
                for (auto &[nr, nc] : dir) {
                    if (r+nr == x && c+nc == y) return steps+1;
                    if (!visited[r+nr][c+nc] ) {
                        Q.push({r+nr, c+nc});
                        visited[r+nr][c+nc] = true;
                    }
                }
            }
            ++steps;
        }
        
        return steps;
    }
};