class Solution {
public:
    int MOD = 1e9 + 7;

    int cal(vector<vector<long>>& dp, int n, int i) {
        
        if (n == 1) return dp[n][i] = 1;
        if (dp[n][i]!= -1) return dp[n][i];
        
        int ans = 0;
        
        switch (i) {
            case 0 : // a 
                ans += cal(dp, n-1, 1), ans %= MOD;
                ans += cal(dp, n-1, 2), ans %= MOD;
                ans += cal(dp, n-1, 4), ans %= MOD;
                break;
            case 1 : // e 
                ans += cal(dp, n-1, 0), ans %= MOD;
                ans += cal(dp, n-1, 2), ans %= MOD;
                break;
            case 2 : // i
                ans += cal(dp, n-1, 1), ans %= MOD;
                ans += cal(dp, n-1, 3), ans %= MOD;
                break;
            case 3 : // o
                ans += cal(dp, n-1, 2), ans %= MOD;
                break;
            case 4 : // u
                ans += cal(dp, n-1, 2), ans %= MOD;
                ans += cal(dp, n-1, 3), ans %= MOD;
                break;   
        }
        
        return dp[n][i] = ans;
    }
    
    
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n+1, vector<long> (5, -1)); // row = len; col = char;
        
        int cnt = 0;
        for(int i = 0; i < 5; i++) {
            cnt += cal(dp, n, i);
            cnt %= MOD;
        }
        
        return cnt;
    }
};