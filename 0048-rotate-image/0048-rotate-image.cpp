class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = n-1;
        int limit = m;
        
        for (int r=0; r< (n>>1); ++r) {
            for (int c=r; c< limit; ++c) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[m-c][r];
                matrix[m-c][r] = matrix[m-r][m-c];
                matrix[m-r][m-c] = matrix[c][m-r];
                matrix[c][m-r] = tmp;
            }
            limit--;
        }

        
    }
};