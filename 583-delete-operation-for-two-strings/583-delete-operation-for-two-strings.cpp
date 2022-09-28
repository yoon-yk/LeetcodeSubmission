class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, 0));
        
        for (int i = 0; i<=n; i++) {
            for (int j = 0; j<=m; j++) {
                if (i == 0 || j == 0 ) {
                    memo[i][j] = i + j;
                } else if (word1[i-1] != word2[j-1]) {
                    memo[i][j] = 1 + min(memo[i][j-1], memo[i-1][j]);
                } else if (word1[i-1] == word2[j-1]) {
                    memo[i][j] = memo[i-1][j-1];
                }
            }
        }
        return memo[n][m];
    }
};