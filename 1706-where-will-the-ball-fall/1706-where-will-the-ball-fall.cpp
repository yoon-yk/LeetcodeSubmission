class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        
        for(int c=0; c<n; c++)
            res.push_back(DFS(0, c, m, n, grid));
        
        return res;
    }
    
    bool valid(int row, int col, int m, int n, vector<vector<int>>& grid) {
        if (col<0 || col>=n ||
            (col == 0) && (grid[row][col] == -1) ||
            (col == n-1) && (grid[row][col] == 1) ||
            (grid[row][col] == 1) && (grid[row][col] != grid[row][col+1]) ||
            (grid[row][col] == -1) && (grid[row][col] != grid[row][col-1])
           )
        return false;
        return true;
    }
    
    int DFS(int row, int col, int m, int n, vector<vector<int>>& grid) {
        if (row == m) return col;
        if (!valid(row, col, m, n, grid)){
            return -1;
        }
        return DFS(row+1, col+grid[row][col], m, n, grid);
    }
};