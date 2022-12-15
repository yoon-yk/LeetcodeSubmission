class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    void mark(vector<vector<char>>& board, int i, int j, int src, int dst) {

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != src)
            return;
        
        board[i][j] = dst;
        
        for (int d=0; d<4; d++) {
            mark(board, i+dir[d], j+dir[d+1], src, dst);
        }    
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        for (int i=0; i<r; ++i) {
            mark(board, i, 0, 'O', 'P');
            mark(board, i, c-1, 'O', 'P');
        }
        for (int i=0; i<c; ++i) {
            mark(board, 0, i, 'O', 'P');
            mark(board, r-1, i, 'O', 'P');
        }
        
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                mark(board, i, j, 'O', 'X');
            }
        }
        
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                mark(board, i, j, 'P', 'O');
            }
        }
        
    }
};