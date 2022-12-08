class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1= word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return minDist(0, 0, word1, word2, dp);
    }
    
    int minDist(int idx1, int idx2, string &w1, string &w2, vector<vector<int>>& dp) {
        
        if (idx1 == w1.size() || idx2 == w2.size()) {
            return max(w2.size()-idx2, w1.size()-idx1);
        } 
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int ans = w1.size() + w2.size();
        if (w1[idx1] == w2[idx2]) ans = min(ans, minDist(idx1+1, idx2+1, w1, w2, dp));
        ans = min(ans, minDist(idx1+1, idx2, w1, w2, dp) + 1); // delete/insert w1
        ans = min(ans, minDist(idx1, idx2+1, w1, w2, dp) + 1); // delete/insert w2
        ans = min(ans, minDist(idx1+1, idx2+1, w1, w2, dp) + 1); // replace
        
        return dp[idx1][idx2] = ans;
    }
};