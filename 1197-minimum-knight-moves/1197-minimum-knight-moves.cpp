class Solution {
public:
    
    int base = 300;
    vector<int> dirX = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dirY = {1, -1, 2, -2, 2, -2, 1, -1};
    
    
    int minKnightMoves(int x, int y) {
        
        if (x==0 && y == 0) return 0;
        
        x+= base, y+= base;
        vector<vector<bool>> visited(605, vector<bool>(605, false));
        queue<pair<int, int>> Q;
        Q.push({base, base});
        visited[base][base] = true;
        
        int newX, newY, size, steps = 0, visitedHash;
        
        while (!Q.empty()) {    
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                int curX = cur.first, curY = cur.second;
                
                for (int i=0; i<8; ++i) {
                    newX = curX + dirX[i], newY = curY + dirY[i];
                    if (newX == x && newY == y) return steps + 1;
                    if (visited[newX][newY]) continue;
                    visited[newX][newY] = true;
                    Q.push({newX, newY});
                }
            }
            ++ steps;
        }
        
        return steps;
    }
};