class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!mat[i][j]) continue;
                if (i > 0 && j > 0) {
                    mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1])) + 1;
                } else mat[i][j] = 1;
                ans += mat[i][j];
            }
        }
        return ans;
    }
};