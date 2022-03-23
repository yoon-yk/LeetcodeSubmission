class Solution {
public:
    
    // aaa
    // aba

    int countSubstrings(string s) {
        int sum = 0;
        for (int i=0; i<s.length(); i++) {
            sum += isPalindromic(s, i, i); // b, aba
            sum += isPalindromic(s, i, i+1); // aa, abba 
        }
        return sum;
    }
    
    // cabac 
    // cabca 
    
    int isPalindromic(string s, int start, int end) {
        
        int paN = 0;
        if (start < 0 || end >= s.length ()) {
            return 0;
        }
                
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            paN += 1;
            start--; end++;
        }
        
        return paN;
    }
};