class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int c=0; c<matrix[0].size(); c++) {
            int curC = c, curR=0;
            while (curR<matrix.size() && curC<matrix[0].size() && 
                   matrix[curR][curC] == matrix[0][c]){
                curR++, curC++;
            }
            if (curR<matrix.size() && curC<matrix[0].size()) return false;
        }
        for (int r=1; r<matrix.size(); r++) {
            int curC = 0, curR=r;
            while (curR<matrix.size() && curC<matrix[0].size() && 
                   matrix[curR][curC] == matrix[r][0]){
                curR++, curC++;
            }
            if (curR<matrix.size() && curC<matrix[0].size()) return false;
        }
        return true;
    }
};