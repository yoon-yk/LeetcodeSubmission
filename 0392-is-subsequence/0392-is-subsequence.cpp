class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sid = 0;
        for (int i=0; i<t.size(); i++) {
            if (sid < s.size() && t[i] == s[sid]) sid++;
        }
        return (sid == s.size());
    }
};