class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i<9; i++){
            vector<bool> check(10, false);
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                else if (check[board[i][j]-'0']) return false;
                check[board[i][j]-'0'] = true;
            }

            vector<bool> check2(10, false);
            for (int j=0; j<9; j++) {
                if (board[j][i] == '.') continue;
                else if (check2[board[j][i]-'0']) return false;
                check2[board[j][i]-'0'] = true;
            }
        
            int basei, basej, curi, curj;
            vector<bool> check3(10, false);
            basei = (i/3)*3;
            basej = ((i%3)*3);
            for (int j=0; j<9; j++) {
                curi = basei+j/3, curj = basej+j%3;
                if (board[curi][curj] == '.') continue;
                else if (check3[board[curi][curj]-'0']) return false;
                check3[board[curi][curj]-'0'] = true;
            }   
        }
        
        return true;
    }
};