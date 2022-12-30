class Solution {
public:
    int wordsTyping(vector<string>& words, int rows, int cols) {
        /*
        hello---
        world---
        hello---
        world---
        
        
        a_bcd_e_
        a_bcd_e_
        
        a_bcd_
        e_a___
        bcd_e_
        a_bcd_
        */
        
        int wid = 0, cleft = cols, ans = 0, prevCnt, curCnt, startIdx;
        vector<pair<int, int>> dp(words.size(), {-1, -1});
        for (int r=0; r<rows; ++r, cleft = cols) {
            if (dp[wid].first!=-1) {
                ans += dp[wid].first;
                wid = dp[wid].second;
                continue;
            }
            startIdx = wid;
            prevCnt = ans;
            while ((cleft-=words[wid].size()) >= 0) {
                if (++wid == words.size()) {++ans; wid=0;}
                cleft -= 1;
            }
            curCnt = ans;
            dp[startIdx] = {curCnt-prevCnt, wid};
        }
        
        return ans;
    }
};