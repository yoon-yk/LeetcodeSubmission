class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> chars(26, 0);
        int maxCnt = INT_MIN, maxChNum;
        for (const char& ch : tasks) {
            chars[ch-'A']++;
            if (maxCnt == chars[ch-'A']) {
                maxChNum++;
            }
            else if (maxCnt < chars[ch-'A']) {
                maxChNum = 1;
                maxCnt = chars[ch-'A'];
            }
        }

        int minRequired = maxCnt + (n * (maxCnt-1)) + (maxChNum-1);
        
        return max((int) tasks.size(), minRequired);
    }
};