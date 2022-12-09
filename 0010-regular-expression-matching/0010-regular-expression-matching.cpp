class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        
        // return true;
        return backtrack(0, 0, s, p, dp);
    }
    
    bool backtrack(int sid, int pid, string &s, string &p, vector<vector<int>>& dp) {
        
        if (pid == p.size())
            return sid == s.size();
        
        if (dp[sid][pid] != -1) return dp[sid][pid];
        
        int ans = false;
        bool firstMatch = (sid < s.size() &&
                          (p[pid] == s[sid] || p[pid] == '.'));
        
        if (pid + 1 < p.size() && p[pid+1] == '*') {
            ans = backtrack(sid, pid+2, s, p, dp) ||
                (firstMatch && backtrack(sid+1, pid, s, p, dp));
        } else {
            ans = firstMatch && backtrack(sid+1, pid+1, s, p, dp);
        }
        
        return dp[sid][pid] = ans;
    }
    
};