class Solution {
public:
    int minDistance(string w1, string w2) {
        int len1= w1.size(), len2 = w2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        int ret;
        for (int idx1=len1; idx1>=0; --idx1) {
            for (int idx2=len2; idx2>=0; --idx2) {
                if (idx1 == len1 || idx2 == len2) {
                    dp[idx1][idx2] = max(len2-idx2, len1-idx1);
                    continue;
                }    
                ret = len2+len1;
                if (w1[idx1] == w2[idx2]) {
                    dp[idx1][idx2] = dp[idx1+1][idx2+1];
                    continue;
                }
                    
                ret = min(ret, dp[idx1+1][idx2] + 1);
                ret = min(ret, dp[idx1][idx2+1] + 1);
                ret = min(ret, dp[idx1+1][idx2+1] + 1);
                dp[idx1][idx2] = ret;
            }
        }
        
        return dp[0][0];
    }
};