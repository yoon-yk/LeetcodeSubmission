class Solution {
public:
    int numDistinct(string s, string t) {
        int mod = 1e9+7;
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
        for (int sid = s.size(); sid >= 0; --sid) {
            for (int tid = t.size(); tid >= 0; --tid) {
                if (tid == t.size()) dp[sid][tid] = 1;
                else if (sid == s.size()) dp[sid][tid] =  0;
                else {
                    dp[sid][tid] = 0;
                    if (s[sid] == t[tid]) 
                        dp[sid][tid] = (dp[sid][tid] + dp[sid+1][tid+1]) % mod;
                    dp[sid][tid] = (dp[sid][tid] + dp[sid+1][tid]) % mod;
                }
            }            
        } 
        return dp[0][0];
    }
};