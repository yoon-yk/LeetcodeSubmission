class Solution {
public:
    int minD(int idx1, int idx2, string word1, string word2, vector<vector<int>>& dp) {
        if (dp[idx1][idx2] != INT_MAX)
            return dp[idx1][idx2];
        
        if (idx1==word1.size()) 
            return dp[idx1][idx2] = word2.size()-idx2;
    
        if (idx2==word2.size()) 
            return dp[idx1][idx2] = word1.size()-idx1;
        
        int ans = (word2.size()-idx2) + (word1.size()-idx1);
        if (word1[idx1]==word2[idx2]) {
            ans = min (ans, minD(idx1+1, idx2+1, word1, word2, dp));
        } else {
            int delW1 = minD(idx1+1, idx2, word1, word2, dp) + 1;
            int delW2 = minD(idx1, idx2+1, word1, word2, dp) + 1;
            int insOrRep = minD(idx1+1, idx2+1, word1, word2, dp) + 1;
            ans = min(ans, min(delW1, min(delW2, insOrRep)));
        }
        
        return dp[idx1][idx2] = ans;
    }
    
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, INT_MAX));
        return minD(0, 0, word1, word2, dp);
    }
};