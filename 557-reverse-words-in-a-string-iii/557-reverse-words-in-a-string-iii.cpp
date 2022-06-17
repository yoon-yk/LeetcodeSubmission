class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end;
        for (int i=0; i<=s.size(); i++){
            if (s[i]==' ' || i==s.size()) {
                end = i;
                reverse(s.begin()+start, s.begin()+end);
                start = i+1;
            }
        }
        return s;
    }
};