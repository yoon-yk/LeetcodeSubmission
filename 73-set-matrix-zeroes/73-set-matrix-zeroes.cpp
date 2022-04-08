class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false;
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        rowZero = true;
                    else 
                        matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // zero out (2-last) rows and cols
        for (int i=1; i<matrix.size(); i++) {
            for (int j=1; j<matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int row=0; row<matrix.size(); row++) {
                matrix[row][0] = 0;
            }
        }
        
        if (rowZero == true) {
            for (int col=0; col<matrix[0].size(); col++) {
                matrix[0][col] = 0;
            }
        } 
           
    }
};