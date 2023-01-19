class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = 0, cur = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == '1') {
                if (cur + pow(2, len) > k) continue;
                cur += pow(2, len);
            } 
            ++len;
        }
        return len;
    }
};