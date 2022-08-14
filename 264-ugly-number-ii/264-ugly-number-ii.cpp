class Solution {
public:
    int nthUglyNumber(int n) {
        
        int idx = 0;
        vector<int> dp(n+1);
        dp[++idx] = 1;
        
        int next, p2 = 1, p3 = 1, p5 = 1;

        while (idx < n) { 
            next = min (dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
            if (next == dp[p2]*2) p2++;
            if (next == dp[p3]*3) p3++;
            if (next == dp[p5]*5) p5++;
            dp[++idx] = next;
        }
        
        return dp[n];
    }
};