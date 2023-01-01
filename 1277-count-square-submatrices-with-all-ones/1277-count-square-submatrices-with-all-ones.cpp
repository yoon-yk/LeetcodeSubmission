class Solution {
public:
    /*
    [0,0,0]
    [0,1,0]
    [0,1,0]
    [1,1,1]
    [1,1,0]
    
    */
    
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxi = min(m, n);
        int ans = 0;
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, 0)));
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]) {
                    if (i-1 >= 0 && j-1 >= 0) 
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    else dp[i][j] = 1;
                } 
                ans += dp[i][j];
            }
            
        }        
        
        return ans;
    }
};