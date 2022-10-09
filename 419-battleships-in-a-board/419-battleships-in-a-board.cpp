class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        /*
        X X . X
        . . . X
        . . . X
        X X . X
        */
        
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'X') {
                    cnt ++; 
                    dfs(board, i, j);
                }
            }
        }        
        
        return cnt;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        
        if (i < 0 || i >=board.size() || j < 0 || j >=board[0].size() || board[i][j] == '.') return;
        
        board[i][j] = '.';
        
        int dir[5] = {-1, 0, 1, 0, -1};
        for (int d=0; d<4; d++) {
            dfs(board, i+dir[d], j+dir[d+1]);
        }
    }
};