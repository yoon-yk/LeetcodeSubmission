using ll = long long;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<ll> dp(n+1, INT_MAX);
        dp[0] = 0;

        int s, e;
        for (int i=0; i<=n; ++i) {
            s = max(0, i-ranges[i]);
            e = min(n, i+ranges[i]);

            for (int j=s; j<=e; ++j) {
                dp[e] = min(dp[e], dp[j]+1);
            }
        }

        if (dp[n] == INT_MAX) return -1;

        return dp[n];
    }
};