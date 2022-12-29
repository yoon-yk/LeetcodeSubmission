class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size()-1;
        while (r < matrix.size() && c >= 0) {
            // cout << matrix[r][c] << endl;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) --c;
            else ++r;
        }
        return false;
    }
};