class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> blockSum(n, vector<int>(m, 0));
        
        int sum = 0;
        
        /*
        1 2 3
        4 5 6
        7 8 9
        
         1  3  6
         5 12 18
        12 27 45
        
        */
        for (int i=0; i<n; i++) { // row
            for (int j=0; j<m; j++) { // col
                if (i > 0) blockSum[i][j] += blockSum[i-1][j];
                if (j > 0) blockSum[i][j] += blockSum[i][j-1];
                if (i > 0 && j > 0) blockSum[i][j] -= blockSum[i-1][j-1];
                blockSum[i][j] += mat[i][j];
            }
        }
        
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                res[i][j] = blockSum[min(i+k, n-1)][min(j+k, m-1)];
                if (i-k-1 >= 0) res[i][j] -= blockSum[i-k-1][min(j+k, m-1)];
                if (j-k-1 >= 0) res[i][j] -= blockSum[min(i+k, n-1)][j-k-1];
                if (i-k-1 >= 0 && j-k-1 >= 0) res[i][j] += blockSum[i-k-1][j-k-1];
            }
        }
        return res;
    }
};