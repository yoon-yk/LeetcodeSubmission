class Solution {
public:
    bool findAns(vector<vector<int>>& dp, int threshold, int l) {
        int ret;
        for (int i=l-1; i<dp.size(); ++i) {
            for (int j=l-1; j<dp[0].size(); ++j) {
                ret = getSum(dp, i, j, l);
                if (ret <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
    int getSum (vector<vector<int>>& dp, int i, int j, int l) {
        int sum = dp[i][j];
        if (i-l>=0) sum -= dp[i-l][j];
        if (j-l>=0) sum -= dp[i][j-l];
        if (i-l>=0 && j-l>=0) sum += dp[i-l][j-l];
        return sum;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> dp = mat;
        for (int i=0; i<mat.size(); ++i) {
            for (int j=0; j<mat[0].size(); ++j) {
                // +up
                if (i>0) dp[i][j] += dp[i-1][j];
                // +left
                if (j>0) dp[i][j] += dp[i][j-1];
                // -dup
                if (i>0 && j>0) dp[i][j] -= dp[i-1][j-1];
            }
        }
        int lenLim = min(mat.size(), mat[0].size()), ret;
        for (int l=lenLim; l>0; --l) {
            if (findAns(dp, threshold, l)) return l;
        }
        return 0;
    }
};