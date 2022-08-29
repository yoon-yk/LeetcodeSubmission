class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i<9; i++){
            vector<int> check(10, 1);
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                else if (--check[board[i][j]-'0'] < 0) return false;
            }

            vector<int> check2(10, 1);
            for (int j=0; j<9; j++) {
                if (board[j][i] == '.') continue;
                else if (--check2[board[j][i]-'0'] < 0) return false;
            }
        
            int curi, curj;
            vector<int> check3(10, 1);
            curi = (i/3)*3;
            curj = ((i%3)*3);
            for (int j=0; j<9; j++) {
                if (board[curi+j/3][curj+j%3] == '.') continue;
                else if (--check3[board[curi+j/3][curj+j%3]-'0'] < 0) return false;
            }   
        }
        
        return true;
    }
};