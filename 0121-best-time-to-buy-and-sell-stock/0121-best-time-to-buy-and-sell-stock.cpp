class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // max day - min day
        int n = prices.size();
        int minPrice = prices[0], ans = 0;
        for (int i=1; i<n; ++i) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return ans;
    }
};