class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row (n);
        row[0] = 1;
        
        int left, top;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0) continue;
                left = (j>0) ? row[j-1] : 0;
                top = (i>0) ? row[j] : 0;
                row[j] = left + top;
            }
        }
        return row[n-1];
    }
};