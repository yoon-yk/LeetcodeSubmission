class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        dp[0][0] = triangle[0][0];
        
        int left = (j > 0) ? dp[i-1][j-1] : 0;
        int right = (j < i) ? dp[i-1][j] : 0;
        dp[i][j] = min(left, right) + triangle[i][j] (i>0 && j>0)
        
        return *min_element(dp.back());
        */
        
        int n = triangle.size();
        vector<int> prev(n), now(n);
        
        int left, right;
        prev[0] = triangle[0][0];
        for (int i=1; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                left = (j>0) ? prev[j-1] : INT_MAX;
                right = (j<i) ? prev[j] : INT_MAX;
                now[j] = min(left, right) + triangle[i][j];
            }
            prev.swap(now);
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};