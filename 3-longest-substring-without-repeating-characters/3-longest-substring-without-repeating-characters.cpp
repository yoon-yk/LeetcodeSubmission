class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0) return 0;
        if (s.length()==1) return 1;
        int left = 0, right = 0, count = 0, maxCount = INT_MIN;
        
        unordered_map <char, int> hashT;
        while (right < s.length()) {
            if (hashT.find(s[right]) == hashT.end()) {
                hashT[s[right]] += 1;
                right++;
                maxCount = max((int)hashT.size(), maxCount);
            }
            else {
                hashT.erase(s[left]);
                left++; 
            }     
        }
     return maxCount;
    }
};