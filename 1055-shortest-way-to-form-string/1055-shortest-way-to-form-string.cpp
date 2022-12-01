class Solution {
public:
    int shortestWay(string s, string t) {
        int sz = s.size(), i = 0, res = 0;
        for (int j = 0; i < t.size() && res <= i + 1; ++j) {
            res += j % sz == 0;
            i += t[i] == s[j % sz];
        }
        return i == t.size() ? res : -1;
    }
};