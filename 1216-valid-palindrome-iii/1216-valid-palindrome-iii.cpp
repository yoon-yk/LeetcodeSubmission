class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<int> memo(n, 0);
        int temp, prev;
        
        for (int i=n-2; i>=0; --i) {
            prev = 0; // memo[i+1][j-1]
            for (int j = i+1; j<n; ++j) {
                temp = memo[j]; // memo[i+1][j]
                
                if (s[i] == s[j]) memo[j] = prev;
                else memo[j] = 1 + min(memo[j], memo[j-1]); // memo[i+1][j] vs memo[i][j-1]
                
                prev = temp;
            }
        }
        
        return memo[n-1] <= k;
    }
};