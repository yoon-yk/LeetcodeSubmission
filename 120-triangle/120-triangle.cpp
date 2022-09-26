class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int>(n, INT_MAX)); // dp [Row][index] = minTotal
        
        dp[0][0] = triangle[0][0];
        for (int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for (int j=1; j<=i; j++) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        
        int minPathSum = INT_MAX;
        for (int j=0; j<n; j++)
           minPathSum = min(minPathSum, dp[n-1][j]);
        
        return minPathSum;
    }
};