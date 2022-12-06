class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        
        /*
        "1"
        dp 
        0 1
        1 1
        
        "13"
        dp
        0 1 2
        1 1 2
        
        "103"
        dp
        0 1 2 3
        1 1 1 1
        */
        
        for (int i=1; i <= s.size(); i++) {
            if ( 0 < (s[i-1]-'0')) dp[i] = dp[i-1]; // as an independent num 
            
            if (i-2 < 0) continue;
            int nn = stoi(s.substr(i-2, 2));
            if (nn > 9 && nn <= 26) dp[i] += dp[i-2]; // as a 2-digit num
        }
        
        return dp[n];
    }
};