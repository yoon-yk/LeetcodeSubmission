class Solution {
public:
    vector<vector<int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1}, 
        {1, -1}, {1, 0}, {1, 1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        int mR = grid.size(), mC = grid[0].size();
        int size, nr, nc, level = 1;
        if (!grid[0][0]) {
            Q.push({0, 0});
            grid[0][0] = 2;
        }
        
        while (!Q.empty()) {
            size = Q.size();
            while (size--) {
                auto [r, c] = Q.front(); Q.pop();
                if (r == mR-1 && c == mC-1) return level;
                
                for (auto & dir : dirs) {
                    nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= mR || nc < 0 || nc >= mC  
                        || grid[nr][nc]!= 0) continue;
                    Q.push({nr, nc});
                    grid[nr][nc] = 2;
                }
            }
            ++level;
        }
        return -1;
    }
};