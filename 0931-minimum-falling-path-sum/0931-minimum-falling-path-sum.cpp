class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        /*
        // base case
        dp[0] = matrix[0];
        
        // recurrence relation
        left = (j>0) ? dp[i-1][j-1] : INT_MAX;
        center = dp[i-1][j];
        right = (j<w-1) ? dp[i-1][j+1] : INT_MAX;
        dp[i][j] = min({left, center, right}) + matrix[i][j];
        */
        
        vector<vector<int>> dp = matrix;
        int left, center, right;
        for (int i=1; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                left = (j>0) ? dp[i-1][j-1] : INT_MAX;
                center = dp[i-1][j];
                right = (j<matrix[0].size()-1) ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] += min({left, center, right});
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
        
    }
};