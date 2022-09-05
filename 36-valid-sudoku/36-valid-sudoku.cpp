class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, int> visit;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                int curN = board[i][j] - '0';
                
                if (visit.count(i*1000 + curN*100) || visit.count(j*100 + curN*10) || visit.count(((i/3)*3+j/3)*10 + curN))
                    return false;
                visit[i*1000 + curN*100]++, visit[j*100 + curN*10]++, visit[((i/3)*3+j/3)*10 + curN]++;
            }
        }
        return true;
    }
};