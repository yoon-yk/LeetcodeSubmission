class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;
        int cur, prev = 1;
        for (int i=1; i<n; ++i) {
            if (i>0 && prices[i-1]-1 == prices[i]) {
                cur = prev+1;
            } else cur = 1;
            ans += cur;
            swap(prev, cur);
        }
        return ans;
    }
};