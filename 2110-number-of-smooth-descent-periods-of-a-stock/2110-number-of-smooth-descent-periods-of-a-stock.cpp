class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        vector<int> dp(n, 1);
        for (int i=0; i<n; ++i) {
            if (i>0 && prices[i-1]-1==prices[i]) {
                dp[i] = dp[i-1] + 1;
            } else dp[i] = 1;
            ans += dp[i];
        }

        /*
        3, 2, 1, 4
        1--2--3--1
        
        */
        return ans;
    }
};