class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> dp(numRows);
        // dp[0].push_back(1);
        
        int curN;
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<i; j++) {
                curN = dp[i-1][j];
                if (j > 0) curN += dp[i-1][j-1]; 
                dp[i].push_back(curN);
            }
            dp[i].push_back(1);
        }
        
        return dp;
    }
};