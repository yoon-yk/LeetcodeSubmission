class Solution {
public:
    string alphabetBoardPath(string target) {
        int cur = 0, idx;
        int kRowSize = 5;
        string ans;
        for (auto& c : target) {
            idx = c-'a';
            ans += string(max(0, (cur/kRowSize-idx/kRowSize)), 'U');
            ans += string(max(0, (idx%kRowSize-cur%kRowSize)), 'R');
            ans += string(max(0, (cur%kRowSize-idx%kRowSize)), 'L');
            ans += string(max(0, (idx/kRowSize-cur/kRowSize)), 'D');
            ans += '!';
            cur = idx;
        }
        return ans;
    }
};