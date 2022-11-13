class Solution {
public:

    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<bitset<10>> row(9), col(9), block(9);
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                int curVal = board[i][j]-'0';
                int blockN = (i/3)*3+(j/3); 
                
                if (row[i][curVal] || col[j][curVal] || block[blockN][curVal])
                    return false;
                row[i].set(curVal);
                col[j].set(curVal);
                block[blockN].set(curVal);
            }
        }
        return true;
    }
};