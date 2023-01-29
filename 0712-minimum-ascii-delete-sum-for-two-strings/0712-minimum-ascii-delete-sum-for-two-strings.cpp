class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        vector<int> ps1(sz1+1), ps2(sz2+1);
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        ps1[0] = ps2[0] = 0;
        for (int i=1; i<=sz1; ++i) ps1[i] = ps1[i-1] + s1[i-1];
        for (int i=1; i<=sz2; ++i) ps2[i] = ps2[i-1] + s2[i-1];
        
        
        return backtrack(s1, s2, 0, 0, ps1, ps2, dp);
    }
    
    int backtrack(string &s1, string &s2, int id1, int id2, 
                  vector<int>& ps1, vector<int>& ps2, vector<vector<int>>& dp) {
        if (id1 == s1.size() || id2 == s2.size()) {
            return max(ps2[s2.size()]-ps2[id2],
                       ps1[s1.size()]-ps1[id1]);
        }
        
        if (dp[id1][id2] != -1) return dp[id1][id2];
        
        int ans = INT_MAX;
        if (s1[id1] == s2[id2]) {
            ans = backtrack(s1, s2, id1+1, id2+1, ps1, ps2, dp);
        } else {
            ans = min(backtrack(s1, s2, id1+1, id2, ps1, ps2, dp) + s1[id1], 
                     backtrack(s1, s2, id1, id2+1, ps1, ps2, dp) + s2[id2]);
        }
        return dp[id1][id2] = ans;
    }
};