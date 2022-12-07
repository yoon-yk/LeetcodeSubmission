class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(n, false);
        for (int end=0; end<n; ++end) {
            for (int start=0; start<=end; ++start) {
                if (start == 0) 
                    dp[end] |= dict.count(s.substr(start, end-start+1));
                else 
                    dp[end] |= dp[start-1] && dict.count(s.substr(start, end-start+1));

            }
        }

        return dp[n-1];
    }
};