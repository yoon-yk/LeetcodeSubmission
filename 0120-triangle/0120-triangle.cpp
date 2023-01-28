class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        dp[0][0] = triangle[0][0];
        
        int left = (j > 0) ? dp[i-1][j-1] : 0;
        int right = (j < i) ? dp[i-1][j] : 0;
        dp[i][j] = min(left, right) + triangle[i][j] (i>0 && j>0)
        
        return *min_element(dp.back());
        */
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        int left, right;
        dp[0][0] = triangle[0][0];
        for (int i=1; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                left = (j>0) ? dp[i-1][j-1] : INT_MAX;
                right = (j<i) ? dp[i-1][j] : INT_MAX;
                dp[i][j] = min(left, right) + triangle[i][j];
            }
        }
        
        return *min_element(dp.back().begin(), dp.back().end());
    }
};