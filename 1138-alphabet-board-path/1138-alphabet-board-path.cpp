class Solution {
public:
    int kRowSize=5;
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    
    inline int getIndex(int r, int c) {
        return r*kRowSize + c;
    }
    
    string alphabetBoardPath(string target) {
        
        string ans;
        int curTarget;
        int r = 0, c = 0, idx = 0;
        while (idx < target.size()) {
            curTarget = target[idx]-'a';
            while (getIndex(r, c) != curTarget) {
                if (getIndex(r, c) < curTarget) {
                    if (curTarget == 25 && c > 0) {
                        --c, ans += 'L';
                    } else {
                        if (curTarget% kRowSize <= c) {
                            ++r, ans += 'D'; // z?
                        } else ++c, ans += 'R';                        
                    }
                } else {
                    if ((curTarget/kRowSize) == r) {
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