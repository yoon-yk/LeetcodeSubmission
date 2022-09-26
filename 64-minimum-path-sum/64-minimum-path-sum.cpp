class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> memo(n, vector<int> (m, 0));
        
        int curMin;
        memo[0][0] = grid[0][0];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i==0 && j==0) continue;
                curMin = INT_MAX;
                if (i>0) curMin = min(curMin, memo[i-1][j]);
                if (j>0) curMin = min(curMin, memo[i][j-1]);
                memo[i][j] = grid[i][j] + curMin;
            }
        }

        return memo[n-1][m-1];
    }
    
    
};