class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void solve(vector<vector<char>>& board) {
        
        int rowSize = board.size(), colSize = board[0].size();
        
        vector<vector<int>> bluePrint(rowSize, vector<int>(colSize, 0));
        
        for (int r=0; r<rowSize; r++) {
            for (int c=0; c<colSize; c++) {
                if (r == 0 || r == rowSize-1 || c == 0 || c == colSize-1 || board[r][c] == 'X')
                    bluePrint[r][c] = -1;
            }
        }
        
        
        for (int r=0; r<rowSize; r++) {
            for (int c=0; c<colSize; c++) {
                if (bluePrint[r][c] == -1 && board[r][c] == 'O') {
                    dfs(r, c, board, bluePrint);

                }
            }
        }
        
        
        for (int r=0; r<rowSize; r++) {
            for (int c=0; c<colSize; c++) {
                if (bluePrint[r][c] == 0)
                    board[r][c] = 'X';
            }
        }   
                
    }
    
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& bluePrint) {
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || (bluePrint[r][c] == -2 ) || (bluePrint[r][c] == -1 && board[r][c] == 'X'))
            return;
        
        bluePrint[r][c] = -2;
        
        for (vector<int>& d : dir)
            dfs(r+d[0], c+d[1], board, bluePrint);
    }
    
};