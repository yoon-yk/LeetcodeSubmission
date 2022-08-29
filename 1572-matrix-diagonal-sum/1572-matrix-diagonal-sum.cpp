class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0, j = 0, sum = 0;
        while (i < n && j < n) {
            sum += mat[i][j];
            i++, j++;
        }
        
        i = 0, j = n-1;
        while (i >= 0 && j >= 0) {
            sum += mat[i][j];
            i++, j--;
        }
        
        return (n%2 == 1)? sum - mat[n>>1][n>>1] : sum;
    }
};