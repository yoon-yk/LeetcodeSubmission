class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void solve(vector<vector<char>>& board) {
        
        int rowSize = board.size(), colSize = board[0].size();
        
        vector<vector<bool>> bluePrint(rowSize, vector<bool>(colSize, true));
        
        for (int r=0; r<rowSize; r++) {
            if (board[r][0] == 'O') 
                dfs(r, 0, board);
            if (board[r][colSize-1] == 'O')
                dfs(r, colSize-1, board);
        }

        
        for (int c=1; c<colSize-1; c++) {
            if (board[0][c] == 'O') 
                dfs(0, c, board);
            if (board[rowSize-1][c] == 'O') 
                dfs(rowSize-1, c, board);
        }
 
        for (int r=0; r<rowSize; r++) { // O (r*c)
            for (int c=0; c<colSize; c++) {
                if (board[r][c] == 'C')
                    board[r][c] = 'O';
                else if (board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }
            
    }
    
    void dfs(int r, int c, vector<vector<char>>& board){
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O')
            return;
        
        board[r][c] = 'C';
        
        for (vector<int>& d : dir)
            dfs(r+d[0], c+d[1], board);
    }
    
};