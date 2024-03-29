class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        base case  
        dp[0][0] = true
        
        recurrence relation
        dp[i][j] = dp[0][i-1] && s.substr(i-1, j-i+1)
        */
        
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=i; ++j) {
                dp[j][i] = dict.count(s.substr(j-1, i-j+1));
                if (dp[0][j-1] && dp[j][i]) {
                    dp[0][i] = true;
                    break;
                }
            }
        }
         
        return dp[0][n];
    }
};