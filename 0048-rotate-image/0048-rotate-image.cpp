class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }
    /*
    
    1 2
    3 4
    5 6
    
    */
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<m; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
    
    void reflect(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(m>>1); ++j) {
                swap(matrix[i][j], matrix[i][m-1-j]);
            }
        }
        
    }
};