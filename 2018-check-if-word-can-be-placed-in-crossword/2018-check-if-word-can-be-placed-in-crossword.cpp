class Solution {
public:
    enum dir{T, R};
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        
        // 각 cell 에 대해서 vertical, horizontal하게 word를 하나씩 넣어본다. 
        // 이 때, vertical하게 놓을거면 위에 빈칸이거나 다른 알파벳이 있으면 안됨
        // horizontal -> 맨 왼쪽에 빈칸이거나 다른 알파벳이 있으면 안됨
        // Dfs 와중에 # 이나 현재 와야하는 알파벳과 맞지 않는 애가 존재하면 바로 return false
        
        // word를 모두 끝낸 다음에, 다음 cell에 빈칸이나 다른 알파벳이 있는지 확인하고 그렇다면 return false;
        
        string rev = word;
        reverse(rev.begin(), rev.end());
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (i == 0 || board[i-1][j] == '#') { // vertical
                    if (dfs(i, j, board, word, 0, T))
                        return true;
                    if (dfs(i, j, board, rev, 0, T))
                        return true;
                }
                if (j == c-1 || board[i][j+1] == '#') { // horizontal 
                    if (dfs(i, j, board, word, 0, R))
                        return true;
                    if (dfs(i, j, board, rev, 0, R))
                        return true;
                } 

            }
        }
        
        
        return false;
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int idx, int dir) {
        
        if (idx == word.size()) {
            bool ret;
            if (dir == T) 
                ret = (i >= board.size() || board[i][j] == '#');
            else 
                ret = (j < 0 || board[i][j] == '#');
            return ret;
        }
        
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#' || (board[i][j]!=' ' && board[i][j] != word[idx]))
            return false;
        
        if (dir == T) return dfs(i+1, j, board, word, idx+1, dir);
        else return dfs(i, j-1, board, word, idx+1, dir);
        
    }
};