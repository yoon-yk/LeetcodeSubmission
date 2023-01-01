class Solution {
public:
    /*
    [0,0,0]
    [0,1,0]
    [0,1,0]
    [1,1,1]
    [1,1,0]
    
    */
    void print(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
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
        
        // cout << ans << endl;
        // print(prev);
        
        for (int sz=2; sz<=maxi; ++sz) {
            for (int i=sz-1; i<m; ++i) {
                for (int j=sz-1; j<n; ++j) {
                    cur[i][j] = false;
                    if (i-1>=0 && j-1>=0 && prev[i-1][j] && prev[i][j-1] && prev[i-1][j-1] && prev[i][j]) {
                        cur[i][j] = true;
                        ++ans;
                    }
                }
            }
            // cout<<sz << "prev" << endl;
            // print(prev);
            // cout<<sz << "cur" << endl;
            // print(cur);
            // cout << ans << endl;
            prev.swap(cur);
        }
        
        return ans;
    }
};