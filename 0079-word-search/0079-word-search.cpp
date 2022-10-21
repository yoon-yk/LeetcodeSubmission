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
                str += board[i][j];
                visited[i][j] = true;
                if (backtrack(i, j, board, visited, str, word))
                    return true;
                visited[i][j] = false;
                str.pop_back();

            }
        }
        
        return false;
    }
    
    bool isInRange(int i, int j, vector<vector<char>>& board, vector<vector<int>> &visited) {
        return (!(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]));
    }
    
    bool backtrack(int i, int j, vector<vector<char>>& board, vector<vector<int>> &visited, string& curStr, string& word){
        
        if (curStr.size() == word.size())
            return (curStr == word);
            
        for (int d=0; d<4; d++) {
            int newI = i+dir[d], newJ = j+dir[d+1];
            if (isInRange(newI, newJ, board, visited)) {
                curStr += board[newI][newJ];
                visited[newI][newJ] = true;
                if (backtrack(newI, newJ, board, visited, curStr, word))
                    return true;
                curStr.pop_back();
                visited[newI][newJ] = false;
            }
        }
        
        return false;
    }
};