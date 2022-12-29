class Solution {
public:

    int minHeightShelves(vector<vector<int>>& books, int maxW) {
        int n = books.size(), j, sum, h;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i=1; i<=n; ++i) {
            dp[i] = dp[i-1] + books[i-1][1];
            
            for (j=i, sum=0, h=0; j>0 && sum + books[j-1][0] <= maxW; --j) {
                sum += books[j-1][0];
                h = max(h, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + h);
            }        
        }
        
        return dp[n];
    }
};