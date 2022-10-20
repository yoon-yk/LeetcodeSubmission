class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX, maxProfit = 0;
        for (int i=0; i<n; i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};