class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size(), m=grid[0].size();
        int curMin;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i==0 && j==0) continue;
                curMin = INT_MAX;
                if (i>0) curMin = min(curMin, grid[i-1][j]);
                if (j>0) curMin = min(curMin, grid[i][j-1]);
                grid[i][j] += curMin;
            }
        }

        return grid[n-1][m-1];
    }
    
    
};