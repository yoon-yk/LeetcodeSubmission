class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int left, top;
        int rsz = grid.size(), csz = grid[0].size();
        for (int i=0; i<rsz; ++i) {
            for (int j=0; j<csz; ++j) {
                // from left or top
                if (i==0 && j == 0) continue;
                left = j > 0 ? grid[i][j-1] : INT_MAX;
                top = i > 0 ? grid[i-1][j] : INT_MAX;
                grid[i][j] += min(left, top);
            }
        }
        return grid[rsz-1][csz-1];
    }
};