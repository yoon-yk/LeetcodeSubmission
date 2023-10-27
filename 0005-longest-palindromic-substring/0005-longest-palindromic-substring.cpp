class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), end, ansStart, ansLen;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len<=n; ++len) {
            for (int start=0; start+len-1<n; ++start) {
                end = start+len-1;
                if (len == 1) dp[start][end] = true;
                else if (len == 2) dp[start][end] = (s[start] == s[end]);
                else dp[start][end] = (dp[start+1][end-1] && s[start]==s[end]);
                
                if (dp[start][end]) {
                    ansStart = start, ansLen = end-start+1;
                }
            }
        }
        return s.substr(ansStart, ansLen);
    }
};