class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.size(), ret;
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int end=1; end<=n; ++end) {
            for (int start=1; start<=end; ++start) {
                ret = (dp[start-1] && dict.count(s.substr(start-1, end-start+1)));
                if (ret) {
                    dp[end] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    
};