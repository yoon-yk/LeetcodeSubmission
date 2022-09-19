class Solution {
public:
    
    int numDecodings(string &s) {
                
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for (int i=0; i<n; i++) {
            
            if (i > 0 && (s[i-1] == '1' || s[i-1] == '2')) {
                string newStr = s.substr(i-1, 2);
                if (stoi(newStr) < 27) 
                    dp[i+1] += dp[i-1];
            }
                        
            if (s[i]!= '0')
                dp[i+1] += dp[i];
        }
        
        return dp[n]; // number of ways to decode the string 
    }
};