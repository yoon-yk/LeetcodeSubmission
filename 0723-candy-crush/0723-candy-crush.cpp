class Solution {
private:
    void crush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
            int k = m-1;
            for (int j = m-1; j >= 0; j--) {
                if (board[j][i] > 0) {
                    board[k][i] = board[j][i];
                    k--;
                }
            }
            for (; k >= 0; k--)
                board[k][i] = 0;
        }
    }
    
    bool preprocess(vector<vector<int>>& board) {
        bool crushable = false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) continue;
                if (j<n-2 && abs(board[i][j]) == abs(board[i][j+1]) && abs(board[i][j+1]) == abs(board[i][j+2])) {
                    board[i][j] = -abs(board[i][j]);
                    board[i][j+1] = -abs(board[i][j]);
                    board[i][j+2] = -abs(board[i][j]);
                    crushable = true;
                }
                    
                if (i<m-2 && abs(board[i][j]) == abs(board[i+1][j]) && abs(board[i+1][j]) == abs(board[i+2][j])) {
                    board[i][j] = -abs(board[i][j]);
                    board[i+1][j] = -abs(board[i][j]);
                    board[i+2][j] = -abs(board[i][j]);
                    crushable = true;
                }   
            }
        }
        return crushable;
    }
    
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (preprocess(board))
            crush(board);
        return board;
    }
};