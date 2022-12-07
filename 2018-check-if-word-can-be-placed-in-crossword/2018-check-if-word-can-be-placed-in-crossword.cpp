class Solution {
public:
    typedef enum {H, V} direction;
    
    bool placeWordInCrossword(vector<vector<char>>& board, string& word) {
        
        string revStr = word;
        reverse(revStr.begin(), revStr.end());
        
        int r = board.size(), c = board[0].size();
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                // horizontal 
                if (i == 0 || board[i-1][j] == '#') {
                    if (dfs(i, j, board, 0, word, V)) return true;
                    if (dfs(i, j, board, 0, revStr, V)) return true;
                }

                // vertical
                if (j == 0 || board[i][j-1] == '#') {
                    if (dfs(i, j, board, 0, word, H)) return true;
                    if (dfs(i, j, board, 0, revStr, H)) return true;
                }
            }
        }
        
        return false;
    }
    
    /*
    
    # #
    # #
    # c
    
    */
    
    
    bool dfs(int r, int c, vector<vector<char>>& board, int idx, string& word,  direction dir) {
                
        // if reached the end, 
            // return true if no more space in the end
            // else return false;
        if (idx == word.size()) {
            if (dir == H) 
                return (c == board[0].size() || board[r][c] == '#');
            else 
                return (r == board.size() || board[r][c] == '#');
        }
        
        // exit
        // if out of range/ or different char exists or is blocked by the wall
        if (r >= board.size() || c >= board[0].size() || board[r][c] == '#' || 
            (board[r][c]!=' ' && board[r][c] != word[idx]))
            return false;
        
        // keep exploring
        if (dir == H) return dfs(r, c+1, board, idx+1, word, dir);
        return dfs(r+1, c, board, idx+1, word, dir);
        
    }
};