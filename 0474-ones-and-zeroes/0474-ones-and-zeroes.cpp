class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<int> oneCnts;
        int oneCnt;
        for (int i=0; i<strs.size(); ++i) {
            oneCnt = 0;
            for (auto &c : strs[i]) {
                if (c == '1') ++oneCnt;
            }
            oneCnts.push_back(oneCnt);
        }
        
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return backtrack(0, strs, oneCnts, dp, m, n);
    }
    
    int backtrack(int i, vector<string>& strs, vector<int> &oneCnts, vector<vector<vector<int>>>& dp, int m, int n) {
        
        if (i == strs.size())
            return 0;

        if (dp[i][m][n] != -1) return dp[i][m][n];
        
        // exclude
        int ans = backtrack(i+1, strs, oneCnts, dp, m, n);
        
        // include 
        int oneCnt = oneCnts[i], zeroCnt = strs[i].size() - oneCnt;
        if (zeroCnt <= m && oneCnt <= n) {
            ans = max(ans, backtrack(i+1, strs, oneCnts, dp, m-zeroCnt, n-oneCnt) + 1);
        }
        
        return dp[i][m][n] = ans;

    }
    
    
};