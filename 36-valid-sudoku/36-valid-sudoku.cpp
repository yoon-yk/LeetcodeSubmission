class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, unordered_set<int>> seenRow;
        unordered_map<int, unordered_set<int>> seenCol;
        unordered_map<int, unordered_set<int>> seenBlock;

        int curN, curR,curC, curB;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                curN = board[i][j] - '0';
                curB = ((i/3)*3+j/3)*10;
                if (seenRow[i].count(curN) || seenCol[j].count(curN) || seenBlock[curB].count(curN))
                    return false;
                seenRow[i].insert(curN), seenCol[j].insert(curN), seenBlock[curB].insert(curN);
            }
        }
        return true;
    }
};