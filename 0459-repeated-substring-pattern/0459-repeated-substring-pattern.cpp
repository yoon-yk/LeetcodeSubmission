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
        string ss = s.substr(0,i);
        int id = 0, sz = ss.size();
        for (auto & c : s) {
            if (c != ss[id % sz]) return false;
            ++id;
        }
        return true;
    }
};