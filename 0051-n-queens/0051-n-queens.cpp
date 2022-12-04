class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for (int i=0; i<n; i++) {
            string s(n, '.');
            board.push_back(s);
        }
        
        vector<bool> rowTaken(n, false), dTaken(2*n, false), adTaken(2*n, false);
        vector<vector<string>> ans;
        
        backtrack(0, board, rowTaken, dTaken, adTaken, ans);
        
        return ans;
    }
    
    /*
    Q . . .
    . Q . .
    */
    void backtrack(int idx, vector<string>& board, vector<bool>& rowTaken,
                   vector<bool>& dTaken, vector<bool>& adTaken, vector<vector<string>>& ans) {
        if (idx == board.size())
            ans.push_back(board);
        
        int n = board.size();
        for (int r=0; r<n; r++) {
            if (rowTaken[r] || dTaken[r+idx] || adTaken[n+r-idx]) continue;
            board[r][idx] = 'Q';
            rowTaken[r] = dTaken[r+idx] = adTaken[n+r-idx] = true;
            backtrack(idx+1, board, rowTaken, dTaken, adTaken, ans);
            rowTaken[r] = dTaken[r+idx] = adTaken[n+r-idx] = false;
            board[r][idx] = '.';
        }
    }
};