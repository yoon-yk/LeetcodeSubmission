class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> freq(26, 0);
        
        for (int i=0; i<s.length(); i++) {
            freq[s[i]-'a']++;
        }
        
        int oddCnt = 0, evenCnt = 0;
        for (int i=0; i<26; i++) {
            if (freq[i]%2 == 1) { // odd
                oddCnt ++;
            } else {
                evenCnt ++;
            }
        }
        
        if (oddCnt > 1) return false;
        return true;
    }
};