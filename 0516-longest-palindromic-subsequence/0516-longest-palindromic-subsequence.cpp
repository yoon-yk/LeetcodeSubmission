class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len=1; len<=n; ++len) {
            for (int start=0, end; start+len-1<n; ++start) {
                end = start + len-1;
                if (len == 1) dp[start][end] = 1;
                else if (s[start] == s[end]) dp[start][end] = dp[start+1][end-1] + 2;
                else dp[start][end] = max(dp[start+1][end], dp[start][end-1]);
            }
        }

        return dp[0][n-1];
    }
    
};