class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), 
                               vector<int> (word2.size(), -1));
        return backtrack(0, 0, word1, word2, dp);
    }
    
    int backtrack(int i1, int i2, string &word1, string &word2, 
                  vector<vector<int>>& dp) {
                
        // base case
        if (i1 == word1.size() || i2 == word2.size()) 
            return max(word1.size()-i1, word2.size()-i2);
        
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        
        
        int max = word1.size() + word2.size();
        int skip = max, insDel = max, rep = max;
        
        // if same
        if (word1[i1] == word2[i2]) 
            skip = backtrack(i1+1, i2+1, word1, word2, dp);
        
        // insert, delete
        insDel = min(backtrack(i1+1, i2, word1, word2, dp),
                  backtrack(i1, i2+1, word1, word2, dp)) + 1;
        
        // replace
        rep = backtrack(i1+1, i2+1, word1, word2, dp) + 1;
        
        return dp[i1][i2] = min({skip, insDel, rep});
    }
};