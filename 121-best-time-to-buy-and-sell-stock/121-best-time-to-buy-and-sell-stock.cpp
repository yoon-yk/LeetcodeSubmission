class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int l=0, r=1, max=0;
        while ((l<r) && (r<prices.size())) { 
            if (prices[r]<=prices[l]) l=r;
            // if (prices[r]<=prices[l]) l+=1;
            else {
                if (prices[r]-prices[l] > max) 
                    max = prices[r]-prices[l];
            }
            r+=1;
        }
        return max;
    }
};