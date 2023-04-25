class Solution {
public:
    int minInsertions(string s) {
        // leetcode
        // leetcode edocteel
        // acbca 
        // b c b
        // aslkdddddfklajdfbca 
        // slkdddddfklajdfbc
        
        // 정의
        // i = start idx of the substring
        // j = end ~
        // dp[i][j] = min
        
        // base case
        // dp[k][k] = 0
        
        // abba
        // recurrence relation
        // dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : min(dp[i+1][j], dp[i][j-1]) + 1
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len=2; len<=n; ++len) {
            for (int start = 0; start + len - 1 < n; ++start) {
                int end = start + len - 1;
                
                if (s[start] == s[end]) {
                    dp[start][end] = dp[start+1][end-1];
                } else {
                    dp[start][end] = min(dp[start+1][end], dp[start][end-1]) + 1;
                }
                
            }
        }
        return dp[0][n-1];
        
    }
};