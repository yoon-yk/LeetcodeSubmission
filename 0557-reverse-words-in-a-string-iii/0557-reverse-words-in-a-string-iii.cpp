class Solution {
public:
    string reverseWords(string s) {
        int lastIdx = 0;
        for (int i=0; i<=s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s.begin()+lastIdx, s.begin()+i);
                lastIdx = i+1;
            }
        }
        return s;
    }
};