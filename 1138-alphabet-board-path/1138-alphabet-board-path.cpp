class Solution {
public:
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    
    
    string alphabetBoardPath(string target) {
        
        int kRow=5;
        string ans;
        char curTarget;
        int r = 0, c = 0, idx = 0;
        while (idx < target.size()) {
            curTarget = target[idx];
            while (board[r][c] != curTarget) {
                if (board[r][c] < curTarget) {
                    if (curTarget == 'z' && c > 0) {
                        --c, ans += 'L';
                    } else {
                        if ((curTarget-'a') % kRow <= c) {
                            ++r, ans += 'D'; // z?
                        } else ++c, ans += 'R';                        
                    }

                } else {
                    if (((curTarget-'a')/kRow) == r) {
                        --c, ans += 'L'; // z?
                    } else --r, ans+= 'U';
                }
            }
            ans += '!';
            ++idx;
        }
        return ans;
    }
    
    
};