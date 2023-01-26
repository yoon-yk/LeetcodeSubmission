class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int hold = -prices[0], nothold = 0, pprevNotHold, prevNotHold = 0;
        for (int i=1; i<prices.size(); ++i) {
            pprevNotHold = prevNotHold, prevNotHold = nothold;
            nothold = max(nothold, hold + prices[i]);
            hold = max(hold, pprevNotHold - prices[i]);
        }

        return max(hold, nothold);
    }
};