class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
                
        int len1 = s1.size(), len2 = s2.size();
        if (len1 + len2 != s3.size()) return false;
        
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, -1));
        return backtrack(s1, s2, s3, 0, 0, dp);
    }
    
    bool backtrack(string& s1, string& s2, string& s3, int idx1, int idx2, vector<vector<int>>& dp) {
        
        int idx3 = idx1 + idx2;
        if (idx3 == s3.size()) {
            return (idx1 == s1.size() && idx2 == s2.size());
        }
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        bool ans = false;
        // s1 끼우기 (하나씩!)
        if (idx1 < s1.size() && s1[idx1] == s3[idx3]) {
            ans |= backtrack(s1, s2, s3, idx1+1, idx2, dp);
        }
        
        // s2 끼우기 (하나씩!)
        if (idx2 < s2.size() && s2[idx2] == s3[idx3]) {
            ans |= backtrack(s1, s2, s3, idx1, idx2+1, dp);
        }
        
        return dp[idx1][idx2] = ans;
    }
};