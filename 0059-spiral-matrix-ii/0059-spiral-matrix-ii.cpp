class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int cnt = n * n;
        int minCol = 0, maxCol = n-1;
        int minRow = 0, maxRow = n-1;
        int number = 1;
        while (number <= n*n) {
            for (int col = minCol; col <= maxCol; ++col) {
                mat[minRow][col] = number++;
            }            
            ++minRow;
            
            for (int row = minRow; row <= maxRow; ++row) {
                mat[row][maxCol] = number++;
            }
            --maxCol;
            
            for (int col = maxCol; col >= minCol; --col) {
                mat[maxRow][col] = number++;
            }
            --maxRow;
            
            for (int row = maxRow; row >= minRow; --row) {
                mat[row][minCol] = number++;
            }
            ++minCol;
            
            --cnt;
        }
        return mat;
    }
};