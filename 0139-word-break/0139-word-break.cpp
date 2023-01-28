class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, false);
        dp[0] = true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for (int i=1; i<=s.size(); ++i) {
            for (int j=1; j<=i; ++j) {
                if (dp[j-1] && dict.count(s.substr(j-1, i-j+1))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};