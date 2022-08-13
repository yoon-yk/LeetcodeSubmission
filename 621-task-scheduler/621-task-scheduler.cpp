class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> chars(26, 0);
        int maxCnt = INT_MIN;
        for (const char& ch : tasks) {
            chars[ch-'A']++;
            maxCnt = max(maxCnt, chars[ch-'A']);
        }
        
        int maxChNum = 0;
        for (int i=0; i<26; i++) {
            if (chars[i] == maxCnt)
                maxChNum ++;
        }
        
        int minRequired = maxCnt + (n * (maxCnt-1)) + (maxChNum-1);
        
        return max((int) tasks.size(), minRequired);
    }
};