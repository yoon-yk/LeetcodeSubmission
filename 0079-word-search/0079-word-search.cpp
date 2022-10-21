class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, false));
        string str;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] != word[0]) continue;
                visited[i][j] = true;
                if (backtrack(1, i, j, board, visited, word))
                    return true;
                visited[i][j] = false;
            }
        }
        
        return false;
    }
    
    bool isInRange(int idx, int i, int j, vector<vector<char>>& board, vector<vector<int>> &visited, string &word) {
        return (!(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || word[idx] != board[i][j]));
    }
    
    bool backtrack(int idx, int i, int j, vector<vector<char>>& board, vector<vector<int>> &visited, string& word){
        
        if (idx == word.size())
            return true;
            
        for (int d=0; d<4; d++) {
            int newI = i+dir[d], newJ = j+dir[d+1];
            if (isInRange(idx, newI, newJ, board, visited, word)) {
                visited[newI][newJ] = true;
                if (backtrack(idx+1, newI, newJ, board, visited, word))
                    return true;
                visited[newI][newJ] = false;
            }
        }
        
        return false;
    }
};