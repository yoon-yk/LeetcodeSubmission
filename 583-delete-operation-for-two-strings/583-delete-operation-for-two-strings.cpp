class Solution {
public:
    int minStep = INT_MAX;
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
    
    // base case 
        // word1 == word2
    // if word1.size() == 0 || word2.size() == 0
        // return;
    // word1 지우거나
        // index 별로 
    // word2 지우거나
        // index 별로
};