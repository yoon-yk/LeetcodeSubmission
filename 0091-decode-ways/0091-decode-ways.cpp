class Solution {
public:
    int numDecodings(string s) {
        
        /*
        base case :
        dp[0] = 1
        recurrence relation :
        dp[i] += dp[i-1] (if s[i] is valid)
        dp[i] += dp[i-2] (if s.substr(i-1,2) is valid)
        */
        
        int num;
        vector<int> dp(s.size()+1);
        dp[0] = 1;
        for (int i=1; i<=s.size(); ++i) {
            if ('1' <= s[i-1] && s[i-1] <= '9') dp[i] += dp[i-1];
            if (i > 1) {
                num = stoi(s.substr(i-2, 2));
                if (10 <= num && num <= 26) dp[i] += dp[i-2]; 
            }
        }
        return dp[s.size()];
    }
};