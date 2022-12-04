class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for (int i=0; i<n; i++) {
            string s(n, '.');
            board.push_back(s);
        }
        
        vector<bool> rowTaken(n, false);
        vector<vector<string>> ans;
        
        backtrack(0, board, rowTaken, ans);
        
        return ans;
    }
    
    bool isTaken(int idx, int row, vector<string>& board) {
        
        int curC = idx, curR = row;
        while (curC >= 0 && curR < board.size()) {
            if (board[curR][curC] == 'Q') return true;
            curC--, curR++;
        }
        curC = idx, curR = row;
        while (curC >= 0 && curR < board.size()) {
            if (board[curR][curC] == 'Q') return true;
            curC--, curR--;
        }
        return false;
    }
    /*
    Q . . .
    . Q . .
    */
    void backtrack(int idx, vector<string>& board, vector<bool>& rowTaken, vector<vector<string>>& ans) {
        if (idx == board.size())
            ans.push_back(board);
        
        for (int r=0; r<board.size(); r++) {
            if (rowTaken[r] || isTaken(idx, r, board)) continue;
            board[r][idx] = 'Q';
            rowTaken[r] = true;
            backtrack(idx+1, board, rowTaken, ans);
            rowTaken[r] = false;
            board[r][idx] = '.';
        }
    }
};