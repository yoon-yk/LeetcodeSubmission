class Solution {
public:
    vector<vector<string>> partition(string s) {
        /// palindrome 
        //// <p * op> or <p op> 
        ///-> aab 
        //// a a b 
        
        int n = s.size();
        vector<string> cur;
        vector<vector<string>> ans;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
   
        for (int i=0; i<n; i++) {
            if (i>0) check(i-1, i, s, dp);
            check(i, i, s, dp);
        }
        
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        
        backtrack(0, s, dp, cur, ans);
        
        return ans;
    }
    
    void check(int sIdx, int eIdx, string & s, vector<vector<bool>>& dp) {
        while (sIdx >= 0 && eIdx < s.size() && s[sIdx] == s[eIdx]) {
            dp[sIdx][eIdx] = true;
            sIdx--, eIdx++;
        }
    }
    
    void backtrack(int idx, string& s, vector<vector<bool>>& dp, vector<string>& cur, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int end=idx; end<s.size(); end++) {
            if (dp[idx][end]) {
                cur.push_back(s.substr(idx, end-idx+1));
                backtrack(end+1, s, dp, cur, ans);
                cur.pop_back();
            }
        }
    }
};