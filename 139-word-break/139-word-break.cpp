class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {     
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        
        for (int i = n; i >= 0; i--)
            for (string& word : wordDict) {
                if (i + word.size() <= n) {
                    for (int j = 0; j < word.size(); j++){
                        if (s[i + j] != word[j])
                            break;
                        if (j == word.size() - 1)
                            dp[i] = dp[i + word.size()];                            
                    }
                }
                if (dp[i]) break;
            }
        
        return dp[0];
    }
};