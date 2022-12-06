class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size(), end, ret, startIdx = -1, len;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l=1; l<=s.size(); ++l) {
            for (int start=0; start+l-1<s.size(); ++start) {
                end = start + l-1; 
                if (l<= 2) ret = (s[start] == s[end]);
                else ret = (s[start]==s[end] && dp[start+1][end-1]);
                dp[start][end] = ret;
                if (ret) startIdx = start, len = l;
            }
        }
        
        return (startIdx == -1) ? "" : s.substr(startIdx, len);
    }
};