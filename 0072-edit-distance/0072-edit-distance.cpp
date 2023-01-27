class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 || word2.size() == 0) {
            return max(word1.size(), word2.size());
        }
        
        vector<vector<int>> dp
            (word1.size()+1, vector<int>(word2.size()+1));
        
        for (int i1 = word1.size(); i1 >= 0; --i1) {
            for (int i2=word2.size(); i2 >= 0; --i2) {
                if (i1 == word1.size() || i2 == word2.size()) {
                    dp[i1][i2] = max(word1.size()-i1, 
                                     word2.size()-i2); // 이만큼 지워줘야 함 
                }else {
                    if (word1[i1] == word2[i2]) 
                        dp[i1][i2] = dp[i1+1][i2+1];
                    else {
                      dp[i1][i2] = min({
                          min(dp[i1+1][i2], dp[i1][i2+1]) + 1,// insert, delete
                          dp[i1+1][i2+1] + 1 // replace
                      });
                    }
                }
            }
        }

        
        return dp[0][0];
    }
};