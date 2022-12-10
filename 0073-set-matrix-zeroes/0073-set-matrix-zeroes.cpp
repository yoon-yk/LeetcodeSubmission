class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size(), c = matrix[0].size();
        vector<int> isRowZero(r, false), isColZero(c, false); 
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (matrix[i][j] == 0){
                    isRowZero[i] = isColZero[j] = true;
                }
            }
        }
        
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (isRowZero[i] || isColZero[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
    }
};