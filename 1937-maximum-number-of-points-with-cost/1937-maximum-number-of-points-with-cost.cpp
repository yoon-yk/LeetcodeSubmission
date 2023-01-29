class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size(), maxPoint;
        vector<long long> l(n), r(n), row(n);
        for (int i=0; i<n; ++i) row[i] = points[0][i];

        for (int i=1; i<m; ++i) {
            
            // left
            l[0] = row[0];
            for (int j=1; j<n; ++j) {
                l[j] = max(row[j], l[j-1]-1);
            }
            
            // right
            r[n-1] = row[n-1];
            for (int j=n-2; j>=0; --j) {
                r[j] = max(row[j], r[j+1]-1);
            }
            
           for (int j=0; j<n; ++j) {
               row[j] = max(l[j], r[j]) + points[i][j];
           }

        }
        
        
        return *max_element(row.begin(), row.end());
    }
};