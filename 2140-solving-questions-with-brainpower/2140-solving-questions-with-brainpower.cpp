class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n-1] = questions[n-1][0];
        
        for (int i=n-2; i>=0; --i) {
            dp[i] = questions[i][0];
            int p = questions[i][0], bp = questions[i][1];
            if (i+bp+1 < n){
                dp[i] = max(dp[i], dp[i+bp+1] + p);
            }
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};