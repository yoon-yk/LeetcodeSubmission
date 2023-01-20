class Solution {
public:
    int checkLength(string &s, int l, int r) {
        // odd len
        int n = s.size(), ans;
        while (0 <= l && r < n) {
            if (s[l] == s[r]) --l, ++r;
            else break;
        }
        ans = (r-1)-(l+1)+1;
        return ans;
    }
    
    string longestPalindrome(string s) {
        int n = s.size(), len = 0, odd, even, startIdx;
        for (int i=0; i<n; ++i) {
            odd = checkLength(s, i-1, i+1); // odd
            if (odd > len) {
                len = odd;
                startIdx = i-(odd>>1);

            }
            even = checkLength(s, i, i+1); // even
            if (even > len) {
                len = even;
                startIdx = i-(even>>1)+1;
            }
        }
        return s.substr(startIdx, len);
    }
    
};