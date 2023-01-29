class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        calculateMatrixSum(mat, dp);
        calculateMatrixBlockSum(dp, mat, k);
        return mat;
    }
    
    void calculateMatrixBlockSum(vector<vector<int>>& dp, vector<vector<int>>& ans, int k) {
        int m = ans.size(), n = ans[0].size();
        int maxIRange, maxJRange, minIRange, minJRange;
        int whole, top, left, diag;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                maxIRange = min(i+1+k, m), maxJRange = min(j+1+k, n);
                minIRange = max(i+1-k-1, 0), minJRange = max(j+1-k-1, 0);
                whole = dp[maxIRange][maxJRange];
                top = dp[minIRange][maxJRange];
                left = dp[maxIRange][minJRange];
                diag = dp[minIRange][minJRange];
                ans[i][j] = whole-(top+left)+diag;
            }
        }

    }
    
    void calculateMatrixSum(vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int m = mat.size(), n = mat[0].size();
        int top, left, diag;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                top = dp[i-1][j];
                left = dp[i][j-1];
                diag = dp[i-1][j-1];
                dp[i][j] = (top+left-diag) + mat[i-1][j-1];
            }
        }
    }
};