class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        int ans = 0, ret;
        for (int i=1; i<=len1; ++i) {
            for (int j=1; j<=len2; ++j) {
                if (text1[i-1] == text2[j-1]) ret = dp[i-1][j-1] + 1;
                else ret = max(dp[i-1][j], dp[i][j-1]);
                ans = max(ans, ret);
                dp[i][j] = ret;
            }
        }
        
        return ans;
    }
};