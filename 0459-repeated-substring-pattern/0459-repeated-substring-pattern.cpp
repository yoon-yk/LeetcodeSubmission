class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i=1; i<(s.size()+1/2); ++i) {
            if (s.size() % i != 0) continue;
            if (possible(s, i)) return true;
        }
        return false;

        // aaa bbb aaa bbb
        // aaa bbb / aaa bbb 
    }

    bool possible(string& s, int i) {
        int id = 0;
        for (auto & c : s) {
            if (c != s[id % i]) return false;
            ++id;
        }
        return true;
    }
};