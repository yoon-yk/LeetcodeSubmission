class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        queue<pair<int, int>> Q;
        
        int r = click[0], c = click[1], nr, nc, res;
        res = mark(board, r, c);
        if (res > 0) {
            board[r][c] = (res + '0');
            return board;
        }
        board[r][c] = 'B';
        Q.push({click[0], click[1]});
        
        while (!Q.empty()) {
            auto [r, c] = Q.front(); Q.pop();
            
            for (auto& [nr, nc] : dir) {
                if (!isValidRange(board, r+nr, c+nc) || board[r+nr][c+nc] != 'E') continue;
                res = mark(board, r+nr, c+nc);
                if (res > 0) {
                    board[r+nr][c+nc] = (res + '0');
                    continue;
                } else {
                    board[r+nr][c+nc] = 'B';
                    Q.push({r+nr, c+nc});
                }
            }
        }
                
        return board;
    }
    
    bool isValidRange(vector<vector<char>>& ref, int i, int j) {
        if (i<0||j<0||i>=ref.size()||j>=ref[0].size()) return false;
        return true;
    }
    
    int mark(vector<vector<char>>& board, int i, int j) {
        int nr, nc, res = 0;
        for (auto & [r, c] : dir) {
            nr = i+r, nc = j+c;
            if (!isValidRange(board, nr, nc)) continue;
            if (board[nr][nc] == 'M') ++res;
        }
        return res;
    }

};