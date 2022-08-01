class Solution {
public:    
    int uniquePaths(int m, int n) {
        vector<vector<int>> map (m, vector<int>(n));
        
        map[0][0] = 1;
        
        // first column
        for (int i=1; i<m; i++)
            map[i][0] = 1;
        
        // first row
        for (int i=1; i<n; i++)
            map[0][i] = 1;
        
        // rest cell
        for (int i=1; i<m; i++) { // row
            for (int j=1; j<n; j++) { // col
                map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }
        
        return map[m-1][n-1];
    }
};