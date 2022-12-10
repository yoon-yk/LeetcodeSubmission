class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size(), c = matrix[0].size();
        bool isFirstCol = false, isFirstRow = false;
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (i==0 && matrix[i][j] == 0) isFirstRow = true;
                if (j==0 && matrix[i][j] == 0) isFirstCol = true;
                if (i!=0 && j!=0 && matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i=r-1; i>=0; --i) {
            for (int j=c-1; j>=0; --j) {
                if (i==0 && isFirstRow) matrix[i][j] = 0;
                if (j==0 && isFirstCol) matrix[i][j] = 0;
                if (i!=0 && j!=0 && (matrix[i][0] == 0 || matrix[0][j] == 0)){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
    }
};