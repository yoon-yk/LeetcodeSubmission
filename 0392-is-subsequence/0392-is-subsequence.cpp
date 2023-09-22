class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;

        int id1 = 0, id2 = 0;
        while (id1 < s.size() && id2 < t.size()) {
            if (s[id1] == t[id2]) {
                ++id1, ++id2;
            } else {
                ++id2;
            }
        }
        return id1 == s.size();
    }


};