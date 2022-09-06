class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<bool>> seenRow(10, vector<bool>(10, false));
        vector<vector<bool>> seenCol(10, vector<bool>(10, false));
        vector<vector<bool>> seenBlock(10, vector<bool>(10, false));

        int curN, curR,curC, curB;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                curN = board[i][j] - '0';
                curB = ((i/3)*3+j/3);
                if (seenRow[i][curN] || seenCol[j][curN] || seenBlock[curB][curN])
                    return false;
                seenRow[i][curN] = true, seenCol[j][curN] = true, seenBlock[curB][curN] = true;
            }
        }
        return true;
    }
};