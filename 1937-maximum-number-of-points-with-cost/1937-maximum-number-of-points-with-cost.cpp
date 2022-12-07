class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int r = points.size(), c = points[0].size();
        int n = points.size();
        
        vector<long long> dp(c, 0), left(c, 0), right(c, 0);
        for (int i=0; i<c; ++i) dp[i] = points[0][i];
        
        for (int i=1; i<r; ++i) {
            
            // left
            left[0] = dp[0];
            for (int j=1; j<c; ++j) {
                left[j] = max(left[j-1]-1, dp[j]);
            }
            // right
            right[c-1] = dp[c-1];
            for (int j=c-2; j>=0; --j) {
                right[j] = max(right[j+1]-1, dp[j]);
            }
            
            for (int j=0; j<c; ++j) {
                dp[j] = max(right[j], left[j]) + points[i][j];
            }
            
        }
        
        return *(max_element(dp.begin(), dp.end()));
    }
};