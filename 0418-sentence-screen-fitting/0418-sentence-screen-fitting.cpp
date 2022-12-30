class Solution {
public:
    int wordsTyping(vector<string>& words, int rows, int cols) {

        int n = words.size();
        int wid = 0, cleft = cols, ans = 0, prevCnt, curCnt, startIdx;
        vector<int> dp(n, -1);
        for (int r=0; r<rows; ++r, cleft = cols) {
            if (dp[wid%n]!=-1) {
                wid += dp[wid%n];
                continue;
            }
            startIdx = wid;
            while ((cleft-=words[wid%n].size()) >= 0) { 
                cleft -= 1, ++wid;
            }
            dp[startIdx%n] = wid-startIdx;
        }
        
        return wid/n;
    }
};