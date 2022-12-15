class Solution {
public:
    /*
    
    (*
    *)
    *()
    (*(
    
    */
    bool checkValidString(string s) {
        vector<unordered_map<int, bool>> dp(s.size());
        
        return backtrack(s, 0, 0, dp);
    }
    
    bool backtrack(string& s, int idx, int opened, vector<unordered_map<int, bool>>& dp) {
        if (idx == s.size()) {
            return (opened == 0);
        }
        
        if (dp[idx].count(opened))
            return dp[idx][opened];
        
        if (s[idx] == '(') {
            return backtrack(s, idx+1, opened+1, dp);
        } else if (s[idx] == ')') {
            return opened > 0 && backtrack(s, idx+1, opened-1, dp);
        }
        
        // open
        int op1 = backtrack(s, idx+1, opened+1, dp);
        // closed
        int op2 = opened > 0 && backtrack(s, idx+1, opened-1, dp);
        // blank
        int op3 = backtrack(s, idx+1, opened, dp);
        
        return dp[idx][opened] = (op1 | op2 | op3);
    }
    
};