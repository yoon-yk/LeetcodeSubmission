class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;
        int len = 1;
        for (int i=1; i<n; ++i) {
            if (i>0 && prices[i-1]-1 == prices[i]) {
                ++len;
            } else len = 1;
            ans += len;
        }
        return ans;
    }
};