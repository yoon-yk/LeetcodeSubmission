class Solution {
public:
    int countVowelPermutation(int n) {
        long dp[2][5]; // row = len; col = char;
        // a=0, e=1, i=2, o=3, u=4;
        int MOD = 1e9 + 7;
        
        int prev = 0, curr = 1;
        for (int i=0; i<5; i++) {
            dp[prev][i] = 0;
            dp[curr][i] = 1;
        }
                
        for (int i=2; i<=n; i++) {
            curr = !curr;
            prev = !prev;
            dp[curr][0] = (dp[prev][1] + dp[prev][2] + dp[prev][4]) % MOD ; // 'a' is following after 'e', 'i', 'u'
            dp[curr][1] = (dp[prev][0] + dp[prev][2]) % MOD; // 'e' is following after 'a', 'i'
            dp[curr][2] = (dp[prev][1] + dp[prev][3]) % MOD; // 'i' is following after 'e', 'o'
            dp[curr][3] = (dp[prev][2]); // 'o' is following after 'i'
            dp[curr][4] = (dp[prev][3] + dp[prev][2]) % MOD; // 'u' is following after 'o', 'i'
        }
        
        int cnt = 0;
        for(int i = 0; i < 5; i++)
            cnt = (cnt + dp[curr][i]) % MOD; 
        
        return cnt;
    }
};