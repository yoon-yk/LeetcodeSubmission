class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> memo(n+1, vector<int> (m+1, 0));
        
        for (int c = m-1; c >= 0; c--) {
            for (int r = n-1; r >= 0; r--) {
                if (text1[r] == text2[c]) {
                    memo[r][c] = 1 + memo[r+1][c+1];
                } else {
                    memo[r][c] = max(memo[r+1][c], memo[r][c+1]);
                }
            }
        }
        
        return memo[0][0];
    }

};