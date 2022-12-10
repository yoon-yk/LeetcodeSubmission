class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        /*
        [ 1, 2, 3]
        [ 4, 5, 6]
        [ 7, 8, 9]
        [10,11,12]
        [13,14,15]
        [16,17,18]
        [19,20,21]
        
        */
        vector<int> ans;
        
        int rowBegin = 0, rowEnd = matrix.size()-1,
        colBegin = 0, colEnd = matrix[0].size()-1;
        
        while (rowBegin <= rowEnd && colBegin <= rowEnd) {
            if (colBegin > colEnd) break;
            for (int c=colBegin; c<=colEnd; ++c) {
                ans.push_back(matrix[rowBegin][c]);
            }
            rowBegin++;
            
            if (rowBegin > rowEnd) break;
            for (int r=rowBegin; r<=rowEnd; ++r) {
                ans.push_back(matrix[r][colEnd]);
            }
            colEnd--;

            if (rowBegin > rowEnd) break;
            for (int c=colEnd; c>=colBegin; --c) {
                ans.push_back(matrix[rowEnd][c]);
            }
            rowEnd--;   

            if (colBegin > colEnd) break;
            for (int r=rowEnd; r>=rowBegin; --r) {
                ans.push_back(matrix[r][colBegin]);
            }
            colBegin++;  

            
        } 
        
        return ans;
    }
};