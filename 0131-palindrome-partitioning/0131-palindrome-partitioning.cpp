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
        
        int end = 0;
        for (int l=1; l<=s.size(); l++) {
            for (int b=0; b+l-1<s.size(); b++) {
                end = b+l-1;
                if (l==1) dp[b][end] = 1;
                else if (l==2) dp[b][end] = (s[b] == s[end]);
                else dp[b][end] = (s[b] == s[end] && dp[b+1][end-1]);
            }
        }

        backtrack(0, s, dp, cur, ans);
        
        return ans;
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