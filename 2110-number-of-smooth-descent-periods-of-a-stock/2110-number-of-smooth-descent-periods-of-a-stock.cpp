class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size(), len = 1;
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            if (i>0 && prices[i-1]-1==prices[i]) {
                ++len;
            } else len = 1;
            ans += len;
        }

        /*
        3, 2, 1, 4
        1--2--3--1
        
        */
        return ans;
    }
};