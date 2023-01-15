class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans = 0, diff, n = a.size(), dp = 0;
        for (int i=2; i<n; ++i) {
            if (a[i] - a[i-1] == a[i-1] - a[i-2]) {
                ++dp;
                ans += dp;
            } else dp = 0;
        }
        return ans;
    }
};