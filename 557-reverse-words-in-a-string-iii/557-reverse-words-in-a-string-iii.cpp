class Solution {
public:
    string reverseWords(string s) {
        string ansStr;
        int cur = 0;
        while (cur < s.size()) {
            
            string curStr;
            while (cur < s.size() && s[cur]!= ' ') {
                curStr = s[cur] + curStr;
                cur++;
            }
            ansStr += curStr;
            if (cur == s.size()) break; 
            ansStr += ' ';
            cur++;

        }
        
        return ansStr;
    }
};