class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int r = points.size(), c = points[0].size();
        vector<long long> dp(c, -1);
        vector<long long> left(c, -1), right(c, -1);
        
        for (int i = 0; i < c; ++i) dp[i] = points[0][i];       
        
        for (int i=1; i<r; ++i) {
            
            left[0] = dp[0];
            for (int lptr=1; lptr<c; ++lptr) 
                left[lptr] = max(left[lptr-1], dp[lptr]+lptr);
            
            right[c-1] = dp[c-1] - c + 1;
            for (int rptr=c-2; rptr>=0; --rptr) 
                right[rptr] = max(right[rptr+1], dp[rptr]-rptr);
            
            for (int j=0; j<c; j++) 
                dp[j] = max(left[j]-j, right[j]+j) + points[i][j];
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};