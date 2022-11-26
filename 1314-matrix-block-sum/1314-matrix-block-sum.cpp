class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> blockSum(n+1, vector<int>(m+1, 0));
        
        for (int i=1; i<=n; i++) { // row
            for (int j=1; j<=m; j++) { // col
                blockSum[i][j] = mat[i-1][j-1]
                    + blockSum[i-1][j]
                    + blockSum[i][j-1]
                    - blockSum[i-1][j-1];
            }
        }
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int maxI = i+1+k, minI = i+1-k, maxJ = j+1+k, minJ = j+1-k;
                res[i][j] = blockSum[min(maxI, n)][min(maxJ, m)]
                    - blockSum[max(minI-1, 0)][min(maxJ, m)]
                    - blockSum[min(maxI, n)][max(minJ-1, 0)]
                    + blockSum[max(minI-1, 0)][max(minJ-1, 0)];
            }
        }
        return res;
    }
};