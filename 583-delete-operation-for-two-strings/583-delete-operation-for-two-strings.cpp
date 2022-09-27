class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, 0));
        
        for (int i = n-1; i>=0; i--) {
            for (int j = m-1; j>=0; j--) {
                if (word1[i] == word2[j])
                    memo[i][j] = 1 + memo[i+1][j+1];
                else 
                    memo[i][j] = max(memo[i+1][j], memo[i][j+1]);
            }
        }
        return (n-memo[0][0]) + (m-memo[0][0]);
    }
};