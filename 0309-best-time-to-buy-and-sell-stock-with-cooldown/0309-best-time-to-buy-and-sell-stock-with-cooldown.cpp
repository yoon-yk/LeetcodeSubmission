class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ret;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        dp[1][true] = -prices[0]; // 첫쨋날에 구입.
        for (int d=2; d<=prices.size(); ++d) {
            // 오늘 구매 (판매한지 2일 이상 지났음) 혹은 기다리기
            dp[d][true] = max(dp[d-2][false] - prices[d-1], dp[d-1][true]);
            
            // 오늘 판매 혹은 기다리기
            dp[d][false] = max(dp[d-1][true] + prices[d-1], dp[d-1][false]);
        }
        return max(dp[n][0], dp[n][1]);
    }
    
};