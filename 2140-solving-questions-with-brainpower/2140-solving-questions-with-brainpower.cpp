class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n); // dp[i] : 인덱스 i ~ (n-1) 까지 얻을 수 있는 포인트의 최대값
        dp[n-1] = questions[n-1][0];
        
        for (int i=n-2; i>=0; --i) {
            int &p = questions[i][0], &bp = questions[i][1];
            dp[i] = p;

            if (i+bp+1 < n){ // solve 
                dp[i] = max(dp[i], dp[i+bp+1] + p);
            }
            dp[i] = max(dp[i], dp[i+1]); // skip
        }
        return dp[0];
    }
};