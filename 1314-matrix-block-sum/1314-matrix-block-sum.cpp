class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        calculateMatrixSum(mat, dp);      
        calculateMatrixBlockSum(dp, mat, k);
        return mat;
    }
    
    
    void calculateSum(vector<vector<int>>& dp, int i, int j, int k, int &whole, int &top, int &left, int &diag) {
        
        int m = dp.size(), n = dp[0].size();
        int maxIRange, maxJRange, minIRange, minJRange;
        
        maxIRange = min(i+k, m-1), maxJRange = min(j+k, n-1);
        minIRange = max(i-k-1, 0), minJRange = max(j-k-1, 0);
        whole = dp[maxIRange][maxJRange];
        top = dp[minIRange][maxJRange];
        left = dp[maxIRange][minJRange];
        diag = dp[minIRange][minJRange];
    }
    
    void calculateMatrixBlockSum(vector<vector<int>>& dp, vector<vector<int>>& ans, int k) {

        int m = ans.size(), n = ans[0].size();
        int maxIRange, maxJRange, minIRange, minJRange;
        int whole, top, left, diag;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                calculateSum(dp, i+1, j+1, k, whole, top, left, diag); 
                ans[i][j] = whole-(top+left)+diag;
            }
        }

    }
    
    void calculateMatrixSum(vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int m = mat.size(), n = mat[0].size();        
        int whole, top, left, diag;
        
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                dp[i][j] = mat[i-1][j-1];
                calculateSum(dp, i, j, 0, whole, top, left, diag); 
                dp[i][j] = whole+(top+left)-diag;
            }
        }
    }
};