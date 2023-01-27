class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int left, top;
        int rsz = grid.size(), csz = grid[0].size();
        vector<int> row(csz, 0);
        row[0] = grid[0][0];
        
        for (int i=0; i<rsz; ++i) {
            for (int j=0; j<csz; ++j) {
                if (i==0 && j == 0) continue;
                
                // from left or top
                left = j > 0 ? row[j-1] : INT_MAX;
                top = i > 0 ? row[j] : INT_MAX;
                row[j] = min(left, top) + grid[i][j];
            }
        }
        return row[csz-1];
    }
};