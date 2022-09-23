class Solution {
public:
    bool isPalindrome(string& s, int start, int end, vector<vector<int>>& dp) {
        if (dp[start][end] != -1) 
            return dp[start][end];

        if (s[start] == s[end] && 
            (end-start <= 1 || isPalindrome(s, start+1, end-1, dp)))
            return dp[start][end] = true;

        return dp[start][end] = false;
    }
    
    string longestPalindrome(string &s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        
        int n= s.length(); 
        for (int i=n-1; i>=0; i--) 
            for (int j=0; i+j<n; j++) 
                if (s[j] == s[j+i] && isPalindrome(s, j, j+i, dp)) 
                    return s.substr(j, i+1);

        return "";
    }
                    
};