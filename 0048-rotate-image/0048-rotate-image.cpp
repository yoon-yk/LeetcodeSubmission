class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = n-1;
        
        /*
        00 01 02
        10 11 12
        20 21 22
        
        
        01 02 03 04 05
        06 07 08 09 10
        11 12 13 14 15
        16 17 18 19 20
        21 22 23 24 25

        */
        
        int limit = m;
        for (int r=0; r< (n>>1); ++r) {
            for (int c=r; c< limit; ++c) {
                // cout << r << c << endl;
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