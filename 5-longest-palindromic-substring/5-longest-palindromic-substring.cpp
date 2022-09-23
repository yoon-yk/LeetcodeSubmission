class Solution {
public:
    string longestPalindrome(string &s) {
        int maxLen = 0, maxStrB, maxStrE;
        for (int i=0; i<s.length(); i++) {
            int oddLen = expandAroundCenter(s, i, i);
            int evenLen = expandAroundCenter(s, i, i+1);
            int localMax = max(oddLen, evenLen);
            if (maxLen < localMax) {
                maxStrB = i - ((localMax - 1) >> 1);
                maxStrE = i + (localMax >> 1);
                maxLen = maxStrE-maxStrB+1;
            }
        }
        
        return s.substr(maxStrB, maxLen);
    }
    
    int expandAroundCenter(string &s, int l, int r) {
        while (l>=0 && r < s.length() && s[l]==s[r]) 
            l--, r++;
        
        return r-l-1;
    }
};