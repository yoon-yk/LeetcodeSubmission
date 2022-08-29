class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++){
            vector<int> check(10, 1);
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                else if (--check[board[i][j]-'0'] < 0) return false;
            }
        }
        
        for (int i=0; i<9; i++) {
            vector<int> check2(10, 1);
            for (int j=0; j<9; j++) {
                if (board[j][i] == '.') continue;
                else if (--check2[board[j][i]-'0'] < 0) return false;
            }
        }
        
        
        int curi, curj;
        for (int i=0; i<9; i++) {
            vector<int> check(10, 1);
            for (int j=0; j<9; j++) {
                curi = ((i/3)*3 + j/3);
                curj = ((i%3)*3) + j%3;
                if (board[curi][curj] == '.') continue;
                else if (--check[board[curi][curj]-'0'] < 0) return false;
            }
        }
        
        return true;
    }
};