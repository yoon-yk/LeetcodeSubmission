class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if (s3.size() != len1 + len2) return false;
        if (len1 == 0 && len2 == 0 && s3.size() == 0) return true;
        
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, false));
        for (int i=len1; i>=0; --i) {
            for (int j=len2; j>=0; --j) {
                int l3 = i+j;
                
                if (i == len1 && j == len2) {
                    dp[i][j] = true;
                } 

                if (j < len2 && s3[l3] == s2[j]) {
                    dp[i][j] |= dp[i][j+1];
                }
                
                if (i < len1 && s3[l3] == s1[i]) {
                    dp[i][j] |= dp[i+1][j];
                }
            }
        }        
        
        return dp[0][0];
    }
};