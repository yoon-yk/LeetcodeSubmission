class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<vector<int>> min_dp(n, vector<int>(n)), max_dp(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            int maxN = nums[i], minN = nums[i];
            min_dp[i][i] = max_dp[i][i] = nums[i];
            
            for (int j=i+1; j<n; ++j) {
                max_dp[i][j] = max(nums[j], max_dp[i][j-1]);
                min_dp[i][j] = min(nums[j], min_dp[i][j-1]);
                ans += max_dp[i][j] - min_dp[i][j];                
            }
            
        }
        return ans;
    }
};