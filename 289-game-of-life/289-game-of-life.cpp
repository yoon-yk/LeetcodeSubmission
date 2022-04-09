class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
        current | next | state
            0       0       0
            1       0       1
            0       1       2
            1       1       3
        */
        
        // Update state 
        for (int row = 0; row<board.size(); row++) {
            for (int col = 0; col<board[0].size(); col++) {
                int neiN = countNei(board, row, col);
                if (board[row][col] == 1) {
                    if (neiN == 2 || neiN == 3) 
                        board[row][col] = 3;
                }
                else if (neiN == 3) board[row][col] = 2;
            }
        }
        
        // 
        for (int row = 0; row<board.size(); row++) {
            for (int col = 0; col<board[0].size(); col++) {
                if (board[row][col] == 0 || board[row][col] == 1)
                    board[row][col] = 0;
                else board[row][col] = 1;
            }
        }
    }
    
    int countNei(vector<vector<int>>& board, int row, int col) {
        int cnt = 0;
        for (int r = row-1; r<row+2; r++){
            for (int c = col-1; c<col+2; c++) {
                if ((r==row && c==col)|| r<0 || c<0 || r>=board.size() || c>=board[0].size()) continue;
                if (board[r][c] == 1 || board[r][c] == 3)
                    cnt ++;
            }
        }
        return cnt;
    }
};