class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        
        return backtrack(0, 0, s, t, dp);
    }
    
    int backtrack(int sid, int tid, string &s, string &t, 
                  vector<vector<int>>& dp) {
        
        int ans = 0;
        
        // base case
        if (tid == t.size()) return 1;
        if (sid == s.size()) return 0;

        if (dp[sid][tid] != -1) return dp[sid][tid];
            
        // recurrence relation
        if (s[sid] == t[tid]) 
            ans += backtrack(sid+1, tid+1, s, t, dp);
        
        ans += backtrack(sid+1, tid, s, t, dp);
        
        return dp[sid][tid] = ans;
    }
    
};