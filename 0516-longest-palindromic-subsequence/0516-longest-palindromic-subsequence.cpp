class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return backtrack(s, 0, n-1, dp);
    }
    
    int backtrack(string& s, int start, int end, vector<vector<int>>& dp) {
        
        if (start > end) return 0;
        if (start == end) return dp[start][end] = 1;
        
        if (dp[start][end] != -1) return dp[start][end];
        
        int ans = 0;
        if (s[start] == s[end]) {
            ans = backtrack(s, start+1, end-1, dp) + 2;
        } else {
            ans = backtrack(s, start+1, end, dp);
            ans = max(ans, backtrack(s, start, end-1, dp));
        }
        return dp[start][end] = ans;
    }
    
};