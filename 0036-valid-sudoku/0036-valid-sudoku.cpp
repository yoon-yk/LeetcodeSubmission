class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> col(10, vector<int>(10, false));
        vector<vector<int>> row(10, vector<int>(10, false));
        vector<vector<int>> cell(10, vector<int>(10, false));
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                
                int curN = board[i][j]-'0';
                if (col[i][curN] == true)
                    return false;
                col[i][curN] = true;
                
                if (row[j][curN] == true)
                    return false;
                row[j][curN] = true;
                
                int curC = (i/3)*3 + (j/3);
                if (cell[curC][curN] == true)
                    return false;
                cell[curC][curN] = true;
            }
        }
        
        return true;
    }
};