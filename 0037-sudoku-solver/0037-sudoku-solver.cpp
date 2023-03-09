class Solution {
public:

    vector<int> rows, cols, subBs;
    
    void seen(int i, int j, int curVal) {
        int rIdx = i, cIdx = j, sbIdx = ((rIdx/3)*3 + (cIdx/3));
        rows[rIdx] |= (1 << curVal);
        cols[cIdx] |= (1 << curVal);
        subBs[sbIdx] |= (1 << curVal);
    }
    
    bool backtrack(vector<vector<char>>& board, vector<pair<int, int>>& toFills, int idx) {
        
        if (idx == toFills.size()) return true; 

        int rIdx = toFills[idx].first, 
            cIdx = toFills[idx].second, 
            sbIdx = ((rIdx/3)*3 + (cIdx/3));

        for (int v=1; v<=9; ++v) {
            if ((rows[rIdx] & (1 << v)) ||
                (cols[cIdx] & (1 << v)) ||
                (subBs[sbIdx] & (1 << v))) continue;    

            board[rIdx][cIdx] = (char)(v + '0');
            rows[rIdx] |= (1 << v);
            cols[cIdx] |= (1 << v);
            subBs[sbIdx] |= (1 << v);

            if (backtrack(board, toFills, idx+1)) return true;

            rows[rIdx] &= ~(1 << v); // 11111 & 11011 = 11011 
            cols[cIdx] &= ~(1 << v);
            subBs[sbIdx] &= ~(1 << v); 
            board[rIdx][cIdx] = '.';

        }
        return false;
}
    
    void solveSudoku(vector<vector<char>>& board) {

        rows.resize(9, 0);
        cols.resize(9, 0);
        subBs.resize(9, 0);
        
        vector<pair<int, int>> toFills;
        for (int i=0; i<board.size(); ++i) { 
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j] != '.') 
                    seen(i, j, board[i][j] - '0');
                else toFills.push_back({i, j});
            }
        }

        backtrack(board, toFills, 0);
        
    }
};