class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        vector<int> count(26);
        int start = 0, maxCount = 0, maxLength = 0;
        int curCh; 
        for (int end = 0; end < len; end++) {
            curCh = s[end] - 'A';
            count[curCh]++;
            
            maxCount = max(maxCount, count[curCh]);
            
            while (end - start + 1 - maxCount > k) {
                count[s[start]- 'A']--;
                start++;
            }
            
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};