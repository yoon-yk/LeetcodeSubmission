class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> memo(n+1, 0);
        memo[0] = 1;
        
        // dp 
        for (int i=1; i<=n; i++) {
            if (s[i-1]-'0' > 0) memo[i] += memo[i-1];
            if (i>1 && ((s[i-2]-'0' == 1) || ((s[i-2]-'0' == 2) && s[i-1]-'0' < 7) )) memo[i] += memo[i-2];
        }
        
        return memo[s.length()];
    }
};