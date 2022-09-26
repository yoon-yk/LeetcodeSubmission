class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, 0));
        
        memo[0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    memo[i][j] = 0; 
                    continue;
                }
                if (i>0) memo[i][j] += memo[i-1][j];
                if (j>0) memo[i][j] += memo[i][j-1];
            }
        }
        
        return memo[n-1][m-1];
    }
};