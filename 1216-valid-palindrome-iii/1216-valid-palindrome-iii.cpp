class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size(), ans = 1, end;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int sz=1; sz<=n; ++sz){
            for (int start=0; start+sz-1<n; ++start) {
                end = start+sz-1;
                if (sz == 1) dp[start][end] = 1;
                else if (sz == 2) dp[start][end] = (s[start] == s[end]) + 1;
                else {
                    if (s[start] == s[end]) {
                        dp[start][end] = dp[start+1][end-1] + 2;
                    } else {
                        dp[start][end] = max(dp[start+1][end], dp[start][end-1]);
                    }
                }
                ans = max(ans, dp[start][end]);

            }
        }
        return ans >= n-k;
    }
};