class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        vector<double> dp(n+1);
        dp[0] = 1;
        double s = k > 0 ? 1 : 0;
        for (int i=1; i<=n; ++i) {
            dp[i] = s/(double)maxPts;
            
            if (i < k) { // 이 이상이면 멈추기 때문에 확률에 포함 X
                s += dp[i];   
            }
            
            if (i-maxPts >= 0 && i - maxPts < k) { // sliding window size maxPts
                s -= dp[i-maxPts];
            }
        }
        return accumulate(dp.begin()+k, dp.end(), 0.0);
    }
};