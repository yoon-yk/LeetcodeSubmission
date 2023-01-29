class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell, buy, prevNotHold = 0, prevHold = -prices[0];
        for (int i=1; i<prices.size(); ++i) {
            sell = prevHold - fee + prices[i];
            buy = prevNotHold - prices[i];
            prevHold = max(prevHold, buy);
            prevNotHold = max(prevNotHold, sell);
        }
        return max(prevHold, prevNotHold);
    }
};