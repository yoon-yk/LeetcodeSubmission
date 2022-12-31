class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return check(s, 0, 0, dp); 
    }
    
    bool check(string &s, int idx, int opened, vector<vector<int>>& dp) {
        if (idx == s.size()) 
            return (opened == 0);
        
        if (dp[idx][opened] != -1)
            return dp[idx][opened];

        bool ret = false;
        if (s[idx] == ')' || s[idx] == '*') {
            if (opened > 0)
                ret |= check(s, idx+1, opened-1, dp);
        } 

        if (s[idx] == '(' || s[idx] == '*') 
            ret |= check(s, idx+1, opened+1, dp);
        
        if (s[idx] == '*') 
            ret |= check(s, idx+1, opened, dp);
            
        return dp[idx][opened] = ret;
    }
};