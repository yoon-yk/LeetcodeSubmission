class Solution {
public:
    int N, M;
    const int MOD = 1e9 + 7;
    int f(int idx, int localMax, int remaining, vector<vector<vector<int>>> &dp) {
        if (idx == N) return !remaining;

        if (remaining < 0) return 0;

        if (dp[idx][localMax][remaining] != -1)
            return dp[idx][localMax][remaining];

        int ans = 0;

        // no counting 
        for (int num = 1; num <= localMax; ++num)
            ans = (ans + f(idx+1, localMax, remaining, dp)) % MOD;

        // counting since it's bigger than the local Max
        for (int num = localMax+1; num <= M; ++num)
            ans = (ans + f(idx+1, num, remaining-1, dp)) % MOD;

        return dp[idx][localMax][remaining] = ans;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        N = n, M = m;
        return f(0, 0, k, dp);
    }
};