class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> row(9, vector<int>(10, false)),
                            col(9, vector<int>(10, false)),
                            block(9, vector<int>(10, false));
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                int curVal = board[i][j]-'0';
                int blockN = (i/3)*3+(j/3); 
                if (row[i][curVal] || col[j][curVal] || block[blockN][curVal])
                    return false;
                row[i][curVal] = true;
                col[j][curVal] = true;
                block[blockN][curVal] = true;
            }
        }
        return true;
    }
};