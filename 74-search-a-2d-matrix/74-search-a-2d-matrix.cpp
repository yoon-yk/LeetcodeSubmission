class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 0) return false;
        int r = matrix.size(), c = matrix[0].size();
        
        // 1. 
        int candR = 0;

        for (int i=0; i<r; i++) { // row 두 줄 이상부터 
            if (matrix[i][0] == target) return true;
            if (matrix[i][0] <= target){
                candR = i;
            }
        }

        // 2. 
        if (matrix[candR][c-1] < target) return false;

        // 3. binary search
        int start = 0, end = c-1, mid;
        while (start <= end) {
            mid = start + (end-start)/2;
            if (matrix[candR][mid] == target){
                return true;
            }
            if (matrix[candR][mid] < target){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        
        return false;
    }
};