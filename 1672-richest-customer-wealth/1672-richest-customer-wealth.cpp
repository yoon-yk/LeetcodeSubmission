class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum, ans = 0;
        for (auto & row : accounts) {
            sum = accumulate(row.begin(), row.end(), 0);
            if (ans < sum) ans = sum;
        }
        return ans;
    }
};