class Solution {
public:
    bool isPalindromic(string& s, int l, int r, bool hint) {
        while (l < r) {
            if (s[l] != s[r]) {
                if (hint) {
                    return isPalindromic(s, l+1, r, false) || 
                        isPalindromic(s, l, r-1, false);
                } else return false;
            } else ++l, --r;
        }
        return (l>=r);
    }
    
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        return isPalindromic(s, l, r, true);
    }
};