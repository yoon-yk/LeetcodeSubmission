class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> subStrM;
        int left = 0, right = 0, len = s.length();
        int maxLen = 0;
        
        while (right < len) {
            if (subStrM.count(s[right])) { // if exists
                while (left < subStrM[s[right]] + 1) { // move left pointer forward until it passes last s[right]
                    subStrM.erase(s[left++]);
                }
            }
            maxLen = max(maxLen, right-left+1);
            subStrM[s[right]] = right;
            right ++;
        }
        
        return maxLen;
    }
};