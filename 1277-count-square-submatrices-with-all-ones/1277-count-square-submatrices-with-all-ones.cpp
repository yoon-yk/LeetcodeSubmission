class Solution {
public:
    /*
    [0,0,0]
    [0,1,0]
    [0,1,0]
    [1,1,1]
    [1,1,0]
    
    */
    
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxi = min(m, n);
        int ans = 0;
        vector<vector<int>> prev = matrix;
        vector<vector<int>> cur(m, vector<int> (n));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans += matrix[i][j];
            }
        }
        
        for (int sz=2; sz<=maxi; ++sz) {
            for (int i=sz-1; i<m; ++i) {
                for (int j=sz-1; j<n; ++j) {
                    cur[i][j] = false;
                    if (prev[i-1][j] && prev[i][j-1] && prev[i-1][j-1] && prev[i][j]) {
                        cur[i][j] = true;
                        ++ans;
                    }
                }
            }
            prev.swap(cur);
        }
        
        return ans;
    }
};