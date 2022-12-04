class Solution {
public:

    bool isValidRange(int r, int c, vector<vector<char>>& board) {
        if (r<0 || r>=board.size() || c < 0 || c>= board[0].size()) return false;
        
        return true;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int r = board.size(), c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (backtrack(i, j, 0, visited, board, word))
                    return true;
            }
        }
        return false;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    bool backtrack(int r, int c, int idx, vector<vector<bool>>& visited, vector<vector<char>>& board, string& word) {

        if (idx == word.size()) {
            return true;
        }

        if (!isValidRange(r,c, board) || word[idx] != board[r][c] || visited[r][c])
            return false;
    
        visited[r][c] = true;
        
        bool ans = false;
        int nextR, nextC;
        for (int d=0; d<4; d++) {
            nextR = r+dir[d], nextC = c+dir[d+1];
            ans |= backtrack(nextR, nextC, idx+1, visited, board, word);
        }
        
        visited[r][c] = false;
            
        return ans; 
        
    }
};