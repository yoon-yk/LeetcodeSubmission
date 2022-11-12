class Solution {
public:
    int INF = INT_MAX;
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    bool isInRange(vector<vector<int>>& rooms, int r, int c) {
        if (r < 0 || r >= rooms.size() || c < 0 || c >= rooms[0].size() || rooms[r][c] != INF) return false; 
        return true;
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        
        // Q 
        queue<pair<int, int>> Q;
        // collect gate
        int r = rooms.size(), c = rooms[0].size();
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (rooms[i][j] == 0) {
                    Q.push({i, j});
                }
            }
        }
        
        // BFS 
        int step = 0;
        while (!Q.empty()) {
            
            for (int size=Q.size()-1; size>=0; size--) {
                auto curPair = Q.front(); Q.pop();
                int curR = curPair.first, curC = curPair.second;
                for (int d=0; d<4; d++) {
                    int neiR = curR+dir[d], neiC = curC+dir[d+1];
                    if (isInRange(rooms, neiR, neiC)) {
                        Q.push({neiR, neiC});
                        rooms[neiR][neiC] = step+1;
                    }
                }
            }
            
            step++;
                        
        }
        // if cell is not -1, continue
        // else if cell is empty, put current dist
        
    }
};