class Solution {
public:
    /*
    
    r = (loc-1)/rowSize
    c = (loc-1)%rowSize
    
     0  1  2  3  4  5 
     6  7  8  9 10 11 
    12 13 14 15 16 17
    18 19 20 21 22 23
    24 25 26 27 28 29
    30 31 32 33 34 35
    
    */
    
    int n, target;
    
    inline pair<int, int> getLoc(int loc) {
        --loc;
        int r = loc/n;
        int c = (r&1) ? (n-1)-loc%n : loc%n ;
        return {(n-1)-r, c};
    }
    
    pair<int, bool>& getNextLoc(vector<vector<int>>& board, pair<int, bool> ret, int i) {
        auto & [loc, itemUsed] = ret;
        loc += i;
        
        if (loc >= target) {
            loc = target;
            return ret;
        }
        
        auto [r, c] = getLoc(loc);
        
        if (board[r][c] != -1) 
            loc = board[r][c];
        
        return ret;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        n = board.size(), target = n*n;
        int level = 0, size;
        queue<pair<int, bool>> Q;
        Q.push({1, false});
        
        vector<int> visited(target+1, 0);
        visited[1] = true;
        
        while (!Q.empty()) {
            size = Q.size();
            while (size--) {
                auto ret = Q.front(); Q.pop();
                auto& [loc, itemUsed] = ret;
                
                if (loc == target) return level;

                for (int i=1; i<=6; ++i) {
                    auto& [nextLoc, itemUsed] = getNextLoc(board, ret, i);
                    if (visited[nextLoc]) continue;
                    visited[nextLoc] = true;
                    Q.push({nextLoc, itemUsed});
                }
            }
            ++level;
        }
        return -1;
    }
};