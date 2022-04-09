class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowSize = mat.size(); int colSize = mat[0].size();
        int top, down, right, left;
        int INF = rowSize + colSize;
        // left and top
        for (int r = 0; r < rowSize; r++) {
            for (int c = 0; c < colSize; c++) {
                if (mat[r][c] == 0) continue;
                top = (r-1 >= 0)? mat[r-1][c] : INF;
                left = (c-1 >= 0)? mat[r][c-1] : INF; 
                mat[r][c] = min(top, left) + 1;
            }
        }
        
        // right and down
        for (int r = rowSize-1; r >= 0; r--) {
            for (int c = colSize-1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                down = (r+1 < rowSize)? mat[r+1][c] : INF;
                right = (c+1 < colSize)? mat[r][c+1] : INF; 
                mat[r][c] = min(mat[r][c], min(down, right)+1);
            }
        }
        return mat;
    }
};