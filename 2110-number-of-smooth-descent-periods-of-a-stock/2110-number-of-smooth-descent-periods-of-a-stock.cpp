class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        long long cur, prev = 1;
        for (int i=0; i<n; ++i) {
            if (i>0 && prices[i-1]-1 == prices[i]) {
                cur = prev+1;
            } else cur = 1;
            ans += cur;
            prev = cur;
        }
        return ans;
    }
};