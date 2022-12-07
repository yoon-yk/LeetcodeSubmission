class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = (s[0]-'0' > 0);
        
        int cn;
        for (int i=1; i<n; ++i) {
            if (s[i]-'0' > 0) dp[i] = dp[i-1];
            
            cn = stoi(s.substr(i-1, 2));
            if (cn <= 26 && cn > 9) dp[i] += (i-2 >= 0) ? dp[i-2] : 1;
        }
        
        return dp[n-1];
    }
};