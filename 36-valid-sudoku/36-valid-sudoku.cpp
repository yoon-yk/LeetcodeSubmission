class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, int> visit;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                int curN = board[i][j] - '0';
                int curR = i*1000 + curN*100;
                int curC = j*100 + curN*10;
                int curB = ((i/3)*3+j/3)*10 + curN;
                if (visit.count(curR) || visit.count(curC) || visit.count(curB))
                    return false;
                visit[curR]++, visit[curC]++, visit[curB]++;
            }
        }
        return true;
    }
};