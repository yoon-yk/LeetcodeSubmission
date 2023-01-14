class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, diff, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 5000));
        for (int sz=2; sz<=nums.size(); ++sz) {
            for (int start=0; start+sz-1<nums.size(); ++start) {
                int end = start+sz-1;
                diff = dp[start][end-1];
                if (sz == 2 || nums[end]-nums[end-1] == diff) {
                    // for (int a=start; a<=end; ++a) {
                    //     cout << nums[a] << " ";
                    // }cout << endl;
                    dp[start][end] = nums[end]-nums[end-1];
                    if (sz > 2) ++ans;
                } else {
                    dp[start][end] = 5000;
                }
            }
        }
        return ans;
    }
};