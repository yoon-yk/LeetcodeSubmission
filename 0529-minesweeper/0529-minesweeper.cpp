class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    void print(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        // print(board);
        
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (board[i][j] == 'M') {
                    mark(mp, board, i, j);
                }
            }
        }
        
        queue<pair<int, int>> Q;
        if (!mp[click[0]].count(click[1])) Q.push({click[0], click[1]});
        else {
            board[click[0]][click[1]] = mp[click[0]][click[1]] + '0';
            return board;
        }
        int nr, nc;
        while (!Q.empty()) {
            auto [r, c] = Q.front(); Q.pop();

            for (auto& [nr, nc] : dir) {
                if (!isValidRange(board, r+nr, c+nc) || board[r+nr][c+nc] != 'E') continue;
                if (mp[r+nr].count(c+nc)){
                    board[r+nr][c+nc] = mp[r+nr][c+nc]+'0';
                    continue;
                }
                board[r+nr][c+nc] = 'B';
                Q.push({r+nr, c+nc});
            }
        }
        
        // print(board);
        
        return board;
    }
    
    bool isValidRange(vector<vector<char>>& ref, int i, int j) {
        if (i<0||j<0||i>=ref.size()||j>=ref[0].size()) return false;
        return true;
    }
    
    void mark(unordered_map<int, unordered_map<int, int>>& mp, vector<vector<char>>& board, int i, int j) {
        int nr, nc;
        for (auto & [r, c] : dir) {
            nr = i+r, nc = j+c;
            if (!isValidRange(board, nr, nc)||board[nr][nc] != 'E') continue;
            ++mp[nr][nc];
            // cout << nr << " " << nc << " " << mp[nr][nc] << endl;
        }
    }

};