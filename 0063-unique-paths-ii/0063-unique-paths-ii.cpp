class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> row (n);
        row[0] = (obstacleGrid[0][0] == 0);
        
        int left, top;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0) continue;
                if (obstacleGrid[i][j] == 1) 
                    row[j] = 0;
                else {
                    left = (j>0) ? row[j-1] : 0;
                    top = (i>0) ? row[j] : 0;
                    row[j] = left + top;
                }
            }
        }
        return row[n-1];
    }
};