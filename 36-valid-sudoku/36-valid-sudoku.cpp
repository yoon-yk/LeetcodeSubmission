class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, unordered_map<int, int>> seenRow;
        unordered_map<int, unordered_map<int, int>> seenCol;
        unordered_map<int, unordered_map<int, int>> seenBlock;

        int curN, curR,curC, curB;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                curN = board[i][j] - '0';
                curB = ((i/3)*3+j/3)*10 + curN;
                if (seenRow[i].count(curN) || seenCol[j].count(curN) || seenBlock[curB].count(curN))
                    return false;
                seenRow[i][curN]++, seenCol[j][curN]++, seenBlock[curB][curN]++;
            }
        }
        return true;
    }
};