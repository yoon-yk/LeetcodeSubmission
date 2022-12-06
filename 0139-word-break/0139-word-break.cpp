class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len=1; len<=n; ++len) {
            for (int start=0, end; start+len-1<n; ++start) {
                end = start + len -1;
                dp[start][end] = dict.count(s.substr(start, len));
            }
        }
        vector<int> bdp(n, -1);

        return backtrack(0, s, dp, bdp);
    }
    
    bool backtrack(int idx, string& s, vector<vector<bool>>& dp, vector<int>& bdp) {
        
        if (idx == s.size())
            return true;

        if (bdp[idx] != -1)
            return bdp[idx];
        
        for (int next=0; next<s.size(); ++next) {
            if (dp[idx][next]) {
                if (backtrack(next+1, s, dp, bdp))
                    return bdp[idx] = true;
            }
        }
        return bdp[idx] = false;
    }
    
};